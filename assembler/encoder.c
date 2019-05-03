/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 15:55:02 by ccepre            #+#    #+#             */
/*   Updated: 2019/05/03 17:10:54 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	write_header(t_instr **instructions, t_writer *writer)
{
	if (write_into_buffer(writer, COREWAR_EXEC_MAGIC, 4))
		return (1);
   	if (write_text(writer, (*instructions)->params->value, PROG_NAME_LENGTH))
		return (1);
	*instructions = (*instructions)->next;
	if (write_into_buffer(writer, 0, 4))
	   return (1);
	if (write_into_buffer(writer, 0, 4))
		return (1);
   	if (write_text(writer, (*instructions)->params->value, COMMENT_LENGTH))
		return (1);
	*instructions = (*instructions)->next;
	if (write_into_buffer(writer, 0, 4))
	   return (1);
	return (0);
}	

static char encoding_byte(t_writer *writer, t_instr *instruction)
{
	t_token	*current;
	char	byte;
	int		i;

	byte = 0;
	i = -1;
	if (BUFF_SIZE_W - writer->cursor + 1 < 1)
		if (concat_output(writer))
			return (1);
	current = instruction->params;
	while (++i < 4)
	{
		byte = byte << 2;
		if (current && current->lexem == REGISTER)
			byte += 1;
		if (current && current->lexem == DIRECT)
			byte += 2;
		if (current && current->lexem == INDIRECT)
			byte += 3;
		if (current)
			current = current->next;
	}
	writer->buff[writer->cursor++] = byte;
	return (0);
}

static int	encode_params(t_writer *writer, t_instr *instruction, t_token **queue,
		unsigned int inst_address)
{
	t_token			*current;
	t_token			*cp;
	unsigned int	nb;
	int				size;
	int				id;

	id = 2;
	current = instruction->params;
	while (current)
	{
		size = give_size_param(instruction->opcode, current->lexem);
		if (*(current->value) == ':')
		{
			current->address = writer->address + writer->cursor;;
			current->inst_address = inst_address;
			current->size = size;
			if (!(cp = copy_token(current)))
				return (1);	
			append_token(queue, cp);
			while (size--)
				writer->buff[writer->cursor++] = 0;
			current = current->next;
			continue ;
		}
		nb = ft_atoi(current->value);
		if (write_into_buffer(writer, nb, size))
			return (-1);
		current = current->next;
	}
	return (0);
}

int			encoder_asm(t_instr *instructions, t_token *labels, char *file_name)
{
	t_writer		writer;
	t_token			*queue;
	unsigned int	inst_address;

	writer.cursor = 0;
	writer.output = NULL;
	writer.address = 0;
	queue = NULL;
	if (write_header(&instructions, &writer))
		return (print_sys_error(errno));
	//printf("\033[H\033[2J");
	while (instructions)
	{
		inst_address = writer.address + writer.cursor;	
		if (instructions->label)
			complete_labels(&writer, instructions->label, labels);
		if (write_into_buffer(&writer, instructions->opcode, 1)\
				|| (g_op_tab[instructions->opcode - 1].enc_byte\
				&& encoding_byte(&writer, instructions))\
				|| encode_params(&writer, instructions, &queue, inst_address))
		{
			free_tokens(&queue);
			ft_strdel(&(writer.output));
			return (print_sys_error(errno));
		}
		instructions = instructions->next;
	}
	if (concat_output(&writer))
		return (print_sys_error(errno));
	insert_value(&(writer.output[136]), writer.address - 2192, 4);
	replace_label_value(&writer, labels, queue);
	free_tokens(&queue);
	if (write_output(&writer, file_name))
	{
		ft_strdel(&(writer.output));
		return (print_sys_error(errno));
	}
	ft_strdel(&(writer.output));
	return (0);
}

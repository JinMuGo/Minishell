/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:52:37 by sanghwal          #+#    #+#             */
/*   Updated: 2023/02/22 19:50:36 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "defines.h"
#include "data_structure.h"
#include "parser.h"
#include "utils.h"

t_list	*tokenize(char *line)
{
	t_list	*tk_list;
	t_list	*tmp;

	tk_list = ft_calloc(sizeof(t_list), 1);
	make_tk_list(&tk_list, line, 0);
	tmp = tk_list->next;
	free(tk_list);
	tk_list = tmp;
	// print_tokenize(tk_list);
	return (tk_list);
}

void	make_tk_list(t_list **tk_list, char *line, int size)
{
	t_stack	quote;

	stack_init(&quote);
	if (line[size] == '\0')
		return ;
	while ((9 <= line[size] && line[size] <= 13) || line[size] == 32)
		size++;
	size += treat_word(tk_list, &line[size], 0, &quote);
	if (quote.arr)
	{
		stack_destory(&quote);
		// int error_handler(ERR_SYN_QUOTE);
	}
	size += treat_pipe(tk_list, &line[size], 0);
	size += treat_rdr(tk_list, &line[size], 0);
	make_tk_list(tk_list, line, size);
}

int	treat_word(t_list **tk_list, char *line, t_tokenize *token, t_stack *qte)
{
	if (!token)
		token = tokenize_init(token, WORD);
	if (line[token->size] == D_QUOTE || line[token->size] == S_QUOTE)
		in_quote(line, token, qte);
	if ((qte->size == 0 && (line[token->size] == '|' || \
		line[token->size] == '<' || \
		line[token->size] == '>' || (9 <= line[token->size] && \
		line[token->size] <= 13) || line[token->size] == 32)) || \
		line[token->size] == '\0')
		return (token_node_add(tk_list, line, token));
	token->size++;
	treat_word(tk_list, line, token, qte);
	return (token->size);
}

int	treat_pipe(t_list **tk_list, char *line, t_tokenize *token)
{
	if (!token)
		token = tokenize_init(token, PIPE);
	if (line[token->size] != '|')
		return (token_node_add(tk_list, line, token));
	token->size++;
	treat_pipe(tk_list, line, token);
	return (token->size);
}

int	treat_rdr(t_list **tk_list, char *line, t_tokenize *token)
{
	if (!token)
		token = tokenize_init(token, RDR);
	if (line[token->size] != '<' && line[token->size] != '>')
		return (token_node_add(tk_list, line, token));
	token->size++;
	treat_rdr(tk_list, line, token);
	return (token->size);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:38:31 by jgo               #+#    #+#             */
/*   Updated: 2023/02/23 19:12:05 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ERR_ARGS "arg error: minishell dosen't take args"

//  File name too long 255 글자기준. 
# define ERR_SYN_RDR_OUT "syntax error: near unexpected token `>'"
# define ERR_SYN_RDR_NL "syntax error: near unexpected token `newline'"
# define ERR_SYN_RDR_IN "syntax error: near unexpected token `<'"
# define ERR_SYN_RDR_PIPE "syntax error: near unexpected token `|'"
# define ERR_SYN_QUOTE "syntax error: unclosed quote"
# define ERR_SYN_ML "syntax error: not support multi-line"

void print_error(char *str);

#endif
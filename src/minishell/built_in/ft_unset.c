/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:15:22 by jgo               #+#    #+#             */
/*   Updated: 2023/05/14 08:54:36 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "defines.h"
#include "utils.h"
#include "error.h"
#include "meta_command.h"
#include "envp_command.h"
#include "built_in.h"

bool	is_valid_arg(char *arg, bool *is_fail)
{
	int	i;

	i = -1;
	while (arg[++i])
	{
		if (is_valid_params(arg[i]) == false)
		{
			prt_built_in_err("unset ", arg, ERR_INVALID_IDENT, EXIT_FAILURE);
			*is_fail = EXIT_FAILURE;
			return (false);
		}
	}
	return (true);
}

int	ft_unset(t_simple_cmd *simple_cmd)
{
	bool	is_fail;
	int		i;

	if (simple_cmd->args[1] == NULL)
		return (EXIT_SUCCESS);
	is_fail = EXIT_SUCCESS;
	if (ft_isdigit(simple_cmd->args[1][0]))
	{
		prt_built_in_err(\
			"unset ", simple_cmd->args[1], ERR_INVALID_IDENT, EXIT_FAILURE);
		is_fail = EXIT_FAILURE;
	}
	i = -1;
	while (simple_cmd->args[++i])
	{
		if (is_valid_arg(simple_cmd->args[i], &is_fail))
			del_envp_elem(simple_cmd->args[i]);
	}
	return (is_fail);
}

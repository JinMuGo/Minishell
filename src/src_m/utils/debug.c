/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:13:57 by jgo               #+#    #+#             */
/*   Updated: 2023/01/29 17:13:49 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    print_list(void *content)
{
    const char **arr = (const char **)content;

    printf("key : %s |||| ", arr[0]);
    printf("value : %s \n", arr[1]);
}
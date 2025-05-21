/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edsardgrisel <edsardgrisel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:33:25 by edsardgrise       #+#    #+#             */
/*   Updated: 2025/05/21 21:23:39 by edsardgrise      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

void	*allocate_content(char *content)
{
	content = malloc(1, sizeof(int));
	if (content == NULL)
		return (NULL);
	*content = ft_atoi(content);
}

t_list	*create_stack_a(int argc, char *argv[])
{
	int		i;
	int		*content;
	t_list	*stack_a;


	i = 1;
	content = allocate_content(argv[i++]);
	if (content == NULL)
		return (NULL);
	stack_a = ft_lstnew(content);
	if (stack_a == NULL)
		return (free(content), NULL);

	while(i < argc - 1)
	{
		content = allocate_content(argv[i++]);
		if (content == NULL)
			return (NULL);
		stack_a = ft_lstnew(content);
		if (stack_a == NULL)
			return (free(content), NULL);
		ft_lstadd_back(&stack_a, ft_lstnew(&content));
	}
	return (stack_a);
}

#include <stdio.h>
int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	// t_list	*stack_b;

	if (argc < 2)
		return (1);
	stack_a = create_stack_a(argc, argv);
	
	t_list	*cur_node;
	cur_node = stack_a;
	while(cur_node)
	{
		printf("%d ->", *(int *)(cur_node->content));
		cur_node = cur_node->next;
	}
	printf("%d", *(int *)(cur_node->content));

}
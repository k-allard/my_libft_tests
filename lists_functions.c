/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 18:20:58 by kallard           #+#    #+#             */
/*   Updated: 2020/05/17 18:20:59 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef	struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// Adds the element ’new’ at the end of the list.
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list		*head;

	if (lst && new)
	{
		head = (*lst);
		if (head == NULL)
			(*lst) = new;
		else
		{
			while (head->next)
				head = head->next;
			head->next = new;
		}
	}
}

// Allocates and returns a new element.
t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

// Deletes with del() and frees the element *lst and it's every successor.
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*arch_elem;

	if (!del || !lst)
		return ;
	while (*lst)
	{
		del((*lst)->content);
		arch_elem = *lst;
		*lst = arch_elem->next;
		free((void *)arch_elem);
	}
	*lst = NULL;
}

// Iterates the list lst and applies f() to the content of each element. 
// Copies lst to a new list dynamically allocated.
// Del() deletes the content of an element if needed.
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*newhead;

	if (!lst)
		return (NULL);
	newlist = ft_lstnew(f(lst->content));
	if (!newlist)
		return (NULL);
	newhead = newlist;
	while (lst)
	{
		if (lst->next)
		{
			if (!(newlist->next = ft_lstnew(f(lst->next->content))))
			{
				ft_lstclear(&newhead, del);
				return (0);
			}
			newlist = newlist->next;
		}
		lst = lst->next;
	}
	newlist->next = NULL;
	return (newhead);
}

void	*to_lower_case(void *content)
{
	char *str = (char *)content;
	int i = 0;
	
	while (str[i])
	{	
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] - ('A' - 'a');
		i++;
	}
	return ((void *)str);
}

void	to_upper_case(void *content)
{
	char *str = (char *)content;
	int i = 0;
	
	while (str[i])
	{	
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - ('a' - 'A');
		i++;
	}
}

// Iterates the list lst and applies f() to the content of each element.
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

void ft_delcontent(void *content)
{
	printf("\x1b[2mDeleting node [%s]. . .\x1b[0m\n", (char *)content);
	free(content);
}

// Deletes content of element lst using del() and frees this element.
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	if (del)
		del(lst->content);
	free((void *)lst);
}

// Returns the last element of the list lst.
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// Counts the number of elements in a list. *lst is the beginning of the list.
int	ft_lstsize(t_list *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

// Adds the element ’new’ at the beginning of the list.
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
		new->next = *lst;
	*lst = new;
}

void ft_lstprint(t_list *p_begin)
{
	printf("\x1b[2mPrinting the whole list. . .\x1b[0m\n");
	t_list *p = p_begin;
	while (p) 
	{
		printf("\x1b[42m[%s]\x1b[0m", p->content);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	char *str = strdup("plant");
	char *str2 = strdup("green");
	char *str3 = strdup("has grown!");

	t_list *experiment; 													//my future linked list!!
	t_list *new;															//list for testing lstmap function


	experiment = (ft_lstnew(str));											//creating node with content "plant"
	ft_lstadd_front(&experiment, ft_lstnew(str2));							//creating new node and adding it at the beginning
	ft_lstprint(experiment);												//printing, should be "green plant"
	printf("My list has %d nodes.\n", ft_lstsize(experiment));				//counting nodes 
	printf("\x1b[2mAdding new node. . .\x1b[0m\n");
	ft_lstadd_back(&experiment, ft_lstnew(str3));							//creating node and adding it at the end
	ft_lstprint(experiment);												//printing, should be "green plant has grown!"
	printf("My list has %d nodes for now.\n", ft_lstsize(experiment));		//counting nodes 
	printf("\x1b[2mApplying lstiter function (with to_upper_case). . .\x1b[0m\n");
	ft_lstiter(experiment, to_upper_case);									//applying function to_upper_case to each node
	ft_lstprint(experiment);												//printing
	printf("\x1b[2mApplying lstmap function (with to_lower_case). . .\x1b[0m\n");
	new = ft_lstmap(experiment, to_lower_case, ft_delcontent);				//applying lstmap with to_lower_case
	// printf("\x1b[2mTHE INITIAL LIST:\x1b[0m\n");
	// ft_lstprint(experiment);												//printing the initial list
	// printf("\x1b[2mNEW LIST:\x1b[0m\n");
	ft_lstprint(new);														//printing newly created list
	printf("The last node is \x1b[42m[%s]\x1b[0m.\n", ft_lstlast(experiment)->content);	//printing the last node
	ft_lstclear(&experiment->next, ft_delcontent);							//deleting 2nd anf 3rd nodes
	ft_lstprint(experiment);												//printing, only the 1st node should remain
	ft_lstdelone(experiment, ft_delcontent);								//deleting content of the 1st node
	ft_lstprint(experiment);												//printing, should be "[]"
	printf("My list has %d nodes for now.\n", ft_lstsize(experiment));		//counting nodes 

	return 0;
}

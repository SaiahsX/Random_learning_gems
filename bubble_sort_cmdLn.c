/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort_cmdLn.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:26:53 by oadewumi          #+#    #+#             */
/*   Updated: 2024/04/02 16:27:09 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to sort an array using bubble sort
void	bubble_sort(int arr[], int n)
{
	int	i;
	int	temp;

	i = 0;
	// Last i elements are already in place
	while (i < n - 1)
	{
// Swap if the element found is greater than the next element
		if (arr[i] > arr[i + 1])
		{
			temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}

//This is the main for mem alloc, str to int conv and passing the sort fn to stdout
int	main(int argc, char *argv[])
{
	int	i;
	int	n;
	int	*arr;

	if (argc < 2)
	{
		printf("Usage: %s <num1> <num2> ... <numN>\n", argv[0]);
		return 1;
	}
	i = 0;
	n = argc - 1;
	arr = (int *)malloc(n * sizeof(int));
	if (arr == NULL)
	{
		printf("Memory allocation failed\n");
		return 1;
	}
    // Convert command line arguments to integers and store them in the array
	while (i < n)
	{
		arr[i] = atoi(argv[i + 1]);
		i++;
	}
    // Sort the array
	bubble_sort(arr, n);
    // Print the sorted array
	printf("Sorted array: ");
	i = 0;
	while (i < n)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
    // Free dynamically allocated memory
	free(arr);
	return 0;
}

// This is a simple main to dispay all the arguments given on stdout
// int	main(int ac, char **av)
// {
// 	int	mine;

// 	if (ac == 2)
// 	{
// 		mine = av[1];
// 		printf("mine: %d\n", mine);
// 	}
// 	return (0);
// }

// This is an elaborate main to display all the args on stdout
// int	main(int argc, char *argv[])
// {
// 	int	i;

// 	i = 0;
// 	printf("Program name is: %s\n", argv[0]);
// 	if (argc == 1)
// 		printf("\nOnly programe name passed\n");
// 	if (argc >= 2)
// 	{
// 		printf("\nYou have entered %d arguments:\n", argc);
// 		printf("\n-----Following are the command line "
// 			"Arguments passed-----\n");
// 	}
// 	while (i < argc)
// 	{
// 		printf("\nargv[%d]: %s\n", i, argv[i]);
// 		//printf("%s\n", argv[argc - 1]);
// 		i++;
// 	}
// 	return (0);
// }

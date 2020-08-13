#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 80000

void InsertionSortAsc(int arr[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int key = arr[i];
		int j = i;
		while (key < arr[j - 1] && j > 0)
		{
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = key;
	}
}

void InsertionSortDesc(int arr[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int key = arr[i];
		int j = i;
		while (key > arr[j - 1] && j > 0)
		{
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = key;
	}
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(int arr[], int n, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] > arr[largest])
		largest = left;

	if (right < n && arr[right] > arr[largest])
		largest = right;

	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapSortMax(int arr[], int n)
{
	// Build heap
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for (int i = n - 1; i >= 0; i--)
	{
		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);
	}
}

void main()
{
	printf("### MENU ###\n");
	printf("0. Exit\n");
	printf("1. n Random Numbers in array\n");
	printf("2. Display the Array\n");
	printf("3. Sort the Array in Ascending Order by using Insertion Sort Algorithm\n");
	printf("4. Sort the Array in Descending Order by using any sorting algorithm\n");
	printf("5. Time Complexity to sort ascending of random data\n");
	printf("6. Time Complexity to sort ascending of data already sorted in ascending order\n");
	printf("7. Time Complexity to sort ascending of data already sorted in descending order\n");
	printf("8. Time Complexity to sort ascending of data for all Cases (Data Ascending, Data in Descending & Random Data) in Tabular form for values n=5000 to 50000, step=5000\n");

	int n;
	clock_t t_asc, t_asc2, t_desc;
	int arr[MAX_SIZE];
	int choice = 0;

	do
	{
		printf("\nEnter Option: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 0:
			return;
			break;

		case 1:
			printf("Enter value of n: ");
			scanf("%d", &n);
			printf("Inserting %d values into array...\n", n);
			for (int i = 0; i < n; i++)
			{
				arr[i] = rand() % 100;
			}
			break;

		case 2:
			printf("Generated Array: ");
			for (int i = 0; i < n; i++)
			{
				printf("%d ", arr[i]);
			}
			printf("\n");
			break;

		case 3:
			printf("Sorting the array (Ascending)...\n");
			t_asc = clock();
			InsertionSortAsc(arr, n);
			t_asc = clock() - t_asc;
			printf("Sorted Array: ");
			for (int i = 0; i < n; i++)
			{
				printf("%d ", arr[i]);
			}
			printf("\n");
			break;

		case 4:
			printf("Sorting the array (Descending)...\n");
			InsertionSortDesc(arr, n);
			printf("Sorted Array: ");
			for (int i = 0; i < n; i++)
			{
				printf("%d ", arr[i]);
			}
			printf("\n");
			break;
		case 5:
			printf("Time Taken To Sort Random Data (Ascending): %f\n", (double)t_asc / (double)CLOCKS_PER_SEC);
			break;
		case 6:
			InsertionSortAsc(arr, n);
			t_asc2 = clock();
			InsertionSortAsc(arr, n);
			t_asc2 = clock() - t_asc2;
			printf("Time Taken To Sort Data Already in Ascending Order (Ascending): %f\n", (double)t_asc2 / (double)CLOCKS_PER_SEC);
			break;
		case 7:
			InsertionSortDesc(arr, n);
			t_desc = clock();
			InsertionSortAsc(arr, n);
			t_desc = clock() - t_desc;
			printf("Time Taken To Sort Data Already in Descending Order (Ascending): %f\n", (double)t_desc / (double)CLOCKS_PER_SEC);
			break;
		case 8:
			printf("n \tData in Asc \tData in Desc \tRandom Data\n");
			for (n = 5000; n <= 50000; n += 5000)
			{
				//data insertion
				for (int i = 0; i < n; i++)
				{
					arr[i] = rand() % 100;
				}
				long int asc, desc, rand;

				//Random
				rand = clock();
				heapSortMax(arr, n);
				rand = clock() - rand;

				//Ascending
				asc = clock();
				heapSortMax(arr, n);
				asc = clock() - asc;

				//Descending 
				InsertionSortDesc(arr, n);
				desc = clock();
				heapSortMax(arr, n);
				desc = clock();
				
				printf("%d\t%f\t%f\t%f\n", n, (double)asc / (double)CLOCKS_PER_SEC, (double)desc / (double)CLOCKS_PER_SEC, (double)rand / (double)CLOCKS_PER_SEC);
			}
			break;
		default:
			break;
		}
	} while (choice != 0);
}
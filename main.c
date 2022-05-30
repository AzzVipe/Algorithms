#include <stdio.h>
#include <stdlib.h>

void main()
{
	int choice;

	while(1){
		 printf("\n\t Algorithm Time Complexity Analysis");
		printf("\n\t-~-~--~-~-~-~-~-~-~-~--~-~-~-~-~-~-~-\n");
		printf("1. Bubble Sort \n");
		printf("2. Selection Sort \n");
		printf("3. Inserting Sort \n");
		printf("4. Merge Sort \n");
		printf("5. Quick Sort \n");
		printf("6. Radix Sort \n");
		printf("00. Exit Program \n");
		scanf("%d",&choice);

		switch(choice){
			case 00: exit(0);
		}
	}

}
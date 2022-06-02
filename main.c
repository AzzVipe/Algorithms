#include <stdio.h>
#include <stdlib.h>

#define BUBBLE_CODE      "src/.bubble.txt"
#define CLEAR_SCR        "\x1b[2J"
#define CLEAR_SCR_HOME   "\x1b[2J\x1b[H"

void clear()
{
	printf(CLEAR_SCR_HOME);
}

void print_menu(void) 
{
	clear();
	printf("\n\t Algorithm Time Complexity Analysis");
	printf("\n\t-~-~--~-~-~-~-~-~-~-~--~-~-~-~-~-~-~-\n");
	printf("1. Bubble Sort \n");
	printf("2. Selection Sort \n");
	printf("3. Inserting Sort \n");
	printf("4. Merge Sort \n");
	printf("5. Quick Sort \n");
	printf("6. Radix Sort \n");
	printf("0. Show Menu\n");
	printf("-1. Exit\n\n");
}
	
void main()
{
	int choice, c;
	size_t rv;
	FILE *fp;
	char buf[10480];

	print_menu();
	while(1) {
		printf("\nYour Choice: ");
		scanf("%d", &choice);
		switch(choice){
			case -1:
				printf("Exiting....\n");
				exit(EXIT_FAILURE);

			case 0: 
				print_menu();
				break;

			case 1:
				if((fp = fopen(BUBBLE_CODE, "r")) == NULL) { // opening the file
					perror("fopen error");
					exit(EXIT_FAILURE);
				}
				clear(); // clearing screen with escape character sequence 
				printf("Code for bubble sort: \n\n");
				while((c = fgetc(fp)) != EOF) { // reading the file fp with fgetc, man fgetc for more detail about the function
					printf("%c", c);
				}
				
				fclose(fp); // closing the file pointer after using
				break;

			/* @TODO: handle all the switch cases */

			default:
				fprintf(stderr, "Invalid Input\n");
				exit(EXIT_FAILURE);
		}
	}

}

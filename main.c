#include <stdio.h>
#include <stdlib.h>

#define BUBBLE_CODE		"src/.bubble.txt"
#define SELECT_CODE		"src/.select.txt"
#define INSERT_CODE		"src/.insert.txt"
#define MERGE_CODE		"src/.merge.txt"
#define QUICK_CODE		"src/.quick.txt"
#define RADIX_CODE		"src/.radix.txt"

#define BUBBLE "bubble"
#define SELECT "select"
#define INSERT "insert"
#define MERGE  "merge"
#define QUICK  "quick"
#define RADIX  "radix"

#define CLEAR_SCR        "\x1b[2J"
#define CLEAR_SCR_HOME	 "\x1b[2J\x1b[H"

struct algorithm {
	int id;
	char *name;
	char *code_dest;
	char *desc;
};

struct algorithm algos[] = {
	{1,  BUBBLE, BUBBLE_CODE, NULL},
	{2,  SELECT, SELECT_CODE, NULL},
	{3,  INSERT, INSERT_CODE, NULL},
	{4,  MERGE,  MERGE_CODE,  NULL},
	{5,  QUICK,  QUICK_CODE,  NULL},
	{6,  RADIX,  RADIX_CODE,  NULL},
	{-1, NULL,   NULL,        NULL}
};

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

int get_algo(int num) {
	for(int i = 0; algos[i].name; i++)
		if(algos[i].id == num) return i;

	return -1;
}

void print_algo(int algo) {
	char *file;
	FILE *fp;
	int c, index;

	if((index = get_algo(algo)) == -1) {
		fprintf(stderr, "Algorithm not found!\n");
		return;
	}

	if((fp = fopen(algos[index].code_dest, "r")) == NULL) { // opening the file
		perror("fopen error");
		exit(EXIT_FAILURE);
	}
	
	clear(); // clearing screen with escape character sequence 
	printf("Code for bubble sort: \n\n");

	while((c = fgetc(fp)) != EOF) { // reading the file fp with fgetc, man fgetc for more detail about the function
		printf("%c", c);
	}
				
	fclose(fp); // closing the file pointer after using
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

			//Bubble Sort
			case 1:
				print_algo(1);
				break;

			//Selection Sort
			case 2:
				print_algo(2);
				break;

			//Insertion Sort
			case 3:
				print_algo(3);
				break;

			//Merge Sort
			case 4:
				print_algo(4);
				break;

			//Quick Sort
			case 5:
				print_algo(5);
				break;

			//Radix Sort
			case 6:
				print_algo(6);

			default:
				fprintf(stderr, "Invalid Input\n");
				exit(EXIT_FAILURE);
		}
	}

}

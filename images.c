//Authors: Jordan Janofsky-Clark & Aidan Kane Chauvin
//Class: CS135
//Assignment: Final Project

#include <stdio.h>
#include <stdbool.h>
#define MAX_COLS 100
#define MAX_ROWS 100

int menu();
int editMenu();
void load(int inputRows, int inputCols, char arrayInput[][inputCols], int *outputRows, int *outputCols);
void crop(char imageArray);
void dim(int inputRows, int inputCols, char arrayInput[][inputCols]);
void brighten(int inputRows, int inputCols, char arrayInput[][inputCols]);
int rotate(char imageArray);
void save();

int main(){
	char imageArray[MAX_ROWS][MAX_COLS];
	int rows, cols, menuChoice = 1, editChoice = 1;
	int fileLoaded = 0;
	while(menuChoice != 0){
		menuChoice = menu();
		switch(menuChoice){
			case 1:
				load(MAX_ROWS, MAX_COLS, imageArray, &rows, &cols);
				fileLoaded = 1;
				break;
			case 2:
				if(fileLoaded == 0){
					printf("Error: Image not loaded.\n");
				} else if (fileLoaded == 1){
					for (int i = 0; i < rows; i++) {
    						for (int j = 0; j < cols; j++) {
        						if(imageArray[i][j] == '0'){
        							printf(" ");
        						} else if (imageArray[i][j] == '1'){
        							printf(".");
        						} else if (imageArray[i][j] == '2'){
        							printf("o");
        						} else if (imageArray[i][j] == '3'){
        							printf("O");
        						} else if (imageArray[i][j] == '4'){
        							printf("0");
        						}
    						}
    						printf("\n");
					}
				}
				break;
			case 3:
				if(fileLoaded == 0){
					printf("Error: Image not loaded.\n");
				} else {
					editChoice = editMenu();
					switch(editChoice){
						case 2:
							dim(rows, cols, imageArray);
							break;
						case 3:
							brighten(rows, cols, imageArray);
							break;
					}
				}
				//save();
				break;
			case 0:
				printf("Goodbye!\n\n");
				break;
			default:
				printf("Invalid option.\n");
				break;
		}
	}
	
	return 0;
}

int menu(){
	int choiceMenu;
	
	printf("\n**ERINSTAGRAM**\n");
	printf("1: Load image\n");
	printf("2: Display image\n");
	printf("3: Edit image\n");
	printf("0: Exit\n\n");
	printf("Choose from one of the options above: ");
	scanf("%i", &choiceMenu);
	printf("\n");
	
	return choiceMenu;
}

int editMenu(){
	int choiceEdit;
	
	printf("\n**EDITING**\n");
	printf("1: Crop image\n");
	printf("2: Dim image\n");
	printf("3: Brighten image\n");
	printf("0: Return to main menu\n\n");
	printf("Choose from one of the options above: ");
	scanf("%i", &choiceEdit);
	printf("\n");
	
	return choiceEdit;
}

void load(int inputRows, int inputCols, char arrayInput[][inputCols], int *outputRows, int *outputCols){
	char fileName[100];
	FILE* file;
	
	printf("What is the name of the image file? ");
	scanf(" %s", fileName);
	file = fopen(fileName, "r");
	if (file == NULL){
		printf("Could not find an image with that filename.\n");
	}
	else{
		printf("Image successfully loaded!\n");
	}
	
    	int row = 0, col = 0;
    	int last_char = 0;
    	
    	while (row < inputRows && (last_char = fgetc(file)) != -1) { 
        	if (last_char == '\n') {
            		arrayInput[row][col] = '\0';
            		row++;
            		col = 0;
            	} else if (col < inputCols - 1) {
            		arrayInput[row][col++] = last_char;
        	}
    	}
    	if (col > 0) {  
        	arrayInput[row][col] = '\0';
    	}
    	row++;
    	*outputRows = row;
    	*outputCols = col;
    	fclose(file);
}

void dim(int inputRows, int inputCols, char arrayInput[][inputCols]){
	for (int i = 0; i < inputRows; i++) {
    		for (int j = 0; j <= inputCols; j++) {
    			switch(arrayInput[i][j]){
    				case '1':
        				arrayInput[i][j] = '0';
        				break;
        			case '2':
        				arrayInput[i][j] = '1';
        				break;
        			case '3':
        				arrayInput[i][j] = '2';
        				break;
        			case '4':
        				arrayInput[i][j] = '3';
        				break;
    			}
    		}
	}
	for (int i = 0; i < inputRows; i++) {
    		for (int j = 0; j <= inputCols; j++) {
        		if(arrayInput[i][j] == '0'){
        			printf(" ");
        		} else if (arrayInput[i][j] == '1'){
        			printf(".");
       			} else if (arrayInput[i][j] == '2'){
        			printf("o");
        		} else if (arrayInput[i][j] == '3'){
        			printf("O");
        		} else if (arrayInput[i][j] == '4'){
        			printf("0");
        		}
    		}
    		printf("\n");
	}
}

void brighten(int inputRows, int inputCols, char arrayInput[][inputCols]){
	for (int i = 0; i < inputRows; i++) {
    		for (int j = 0; j <= inputCols; j++) {
    			switch(arrayInput[i][j]){
    				case '0':
        				arrayInput[i][j] = '1';
        				break;
        			case '1':
        				arrayInput[i][j] = '2';
        				break;
        			case '2':
        				arrayInput[i][j] = '3';
        				break;
        			case '3':
        				arrayInput[i][j] = '4';
        				break;
    			}
    		}
	}	
}

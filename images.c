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
void crop(int inputRows, int inputCols, char arrayInput[][inputCols]);
char dim(char inputValue);
char brighten(char inputValue);
void save(int inputRows, int inputCols, char arrayInput[][inputCols]);

int main(){
	char imageArray[MAX_ROWS][MAX_COLS], newImage[MAX_ROWS][MAX_COLS];
	int rows, cols, menuChoice = 1, editChoice = 1;
	int fileLoaded = 0;
	while(menuChoice != 0){
		menuChoice = menu();
		switch(menuChoice){
			case 1:
				load(MAX_ROWS, MAX_COLS, imageArray, &rows, &cols);
				fileLoaded = 1;
				newImage[MAX_ROWS][MAX_COLS] = imageArray[MAX_ROWS][MAX_COLS];
				break;
			case 2:
				if(fileLoaded == 0){
					printf("Error: Image not loaded.\n");
				} else if (fileLoaded == 1){
					for (int i = 0; i <= rows; i++) {
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
				} else if (fileLoaded == 1) {
					editChoice = editMenu();
					switch(editChoice){
						case 1:
							for (int i = 0; i <= rows; i++) {
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
							crop(rows, cols, imageArray);
							break;
						case 2:
							for (int i = 0; i < rows; i++) {
    								for (int j = 0; j < cols; j++) {
        								if(imageArray[i][j] != '0'){
        									imageArray[i][j] = dim(imageArray[i][j]);
        									
        								}
    								}
							}
							for (int i = 0; i <= rows; i++) {
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
							save(rows, cols, imageArray);
							break;
						case 3:
							for (int i = 0; i < rows; i++) {
    								for (int j = 0; j < cols; j++) {
        								if(imageArray[i][j] != '4'){
        									imageArray[i][j] = brighten(imageArray[i][j]);
        								}
    								}
							}
							for (int i = 0; i <= rows; i++) {
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
							save(rows, cols, imageArray);
							break;
					}
				
				break;
			case 0:
				printf("Goodbye!\n\n");
				break;
			default:
				printf("Invalid option.\n");
				break;
		}
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
            		row++;
            		col = 0;
            	} else if (col < inputCols - 1) {
            		arrayInput[row][col++] = last_char;
        	}
    	}
    	*outputRows = row;
    	*outputCols = col;
    	fclose(file);
}

char dim(char inputValue){
	char outputValue;
	switch(inputValue){
		case '4':
			outputValue = '3';
			break;
		case '3':
			outputValue = '2';
			break;
		case '2':
			outputValue = '1';
			break;
		case '1':
			outputValue = '0';
			break;
	}
	return outputValue;
}

char brighten(char inputValue){
	char outputValue;
	switch(inputValue){
		case '0':
			outputValue = '1';
			break;
		case '1':
			outputValue = '2';
			break;
		case '2':
			outputValue = '3';
			break;
		case '3':
			outputValue = '4';
			break;
	}
	return outputValue;
}

void save(int inputRows, int inputCols, char arrayInput[][inputCols]){
	char choice;
	char newFileName[100];
	FILE* fptr;
	
	printf ("Would you like to save the file? (y/n) ");
	scanf (" %c", &choice);
	
	if (choice == 'y' || choice == 'Y'){
		printf ("What do you want to name the image file? (include the extension) ");
		scanf("%s", newFileName);
		
		fptr = fopen (newFileName, "w");
		if (fptr == NULL){
			printf("Error opening file.\n");
		}
		
		else{
			for (int index1 = 0; index1 < inputRows; index1++){
				for (int index2 = 0; arrayInput[index1][index2] != '\0'; index2++){
					fprintf (fptr, "%c", arrayInput[index1][index2]);
				}
				fprintf (fptr, "\n");
			}
			fclose (fptr);
		}
	}
}

void crop(int inputRows, int inputCols, char arrayInput[][inputCols]){
	char choice;
	int newLeftCol, newRightCol, newTopRow, newBottomRow, base, height;
	
	printf("The image you want to crop is %d x %d\n", inputRows, inputCols);
	printf("The row and column values start in the upper lefthand corner.\n");
	printf("\nwhich column do you want to be the new left side? ");
	scanf("%d", &newLeftCol);
	printf("\nWhich column do you want to be the new right side? ");
	scanf("%d", &newRightCol);
	printf("\nWhich row do you want to be the new top? ");
	scanf("%d", &newTopRow);
	printf("\nWich row do you want to be the new botom? ");
	scanf("%d", &newBottomRow);
	
	base = newRightCol - newLeftCol + 1;
	height = newBottomRow - newTopRow + 1;
	
	char newImage[height][base];
	
	for (int index1 = 0; index1 < height; index1++){
		for (int index2 = 0; index2 < base; index2++){
			newImage[index1][index2] = arrayInput[index1+(newTopRow-1)][index2+(newLeftCol-1)];
		}
	}
	for (int i = 0; i < height; i++) {
    		for (int j = 0; j < base; j++) {
        		if(newImage[i][j] == '0'){
        			printf(" ");
        		} else if (newImage[i][j] == '1'){
        			printf(".");
        		} else if (newImage[i][j] == '2'){
        			printf("o");
        		} else if (newImage[i][j] == '3'){
        			printf("O");
        		} else if (newImage[i][j] == '4'){
        			printf("0");
        		}
    		}
    		printf("\n");
	}
	save(height, base, newImage);
}

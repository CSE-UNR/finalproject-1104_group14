//Authors: Jordan Janofsky-Clark & Aidan Kane Chauvin
//Class: CS135
//Assignment: Final Project

#include <stdio.h>
#include <stdbool.h>

int menu();
int editMenu();
void display(int imageArray);
int crop(int imageArray);
int dim(int imageArray);
int brighten(int imageArray);
int rotate(int imageArray);
// save function

int main(){

	/*
	menuChoice = menu();
	switch(menuChoice){
		case 1:
			//loading stuff
			break;
		case 2:
			display();
			break;
		case 3:
			editChoice = editMenu();
			switch(editChoice){
				
			}
			break;
			save();
		case 0:
			// say goodbye
			break;
		default:
			//invalid
			break;
	}
	*/
	
	//loop[START] (while menu() != 0)
	//menu()
		//load
		//display
		//edit -> editMenu()
			//crop
			//dim
			//brighten
			//rotate
		//save?
	//loop[END]

	return 0;
}

int menu(){
	int choiceMenu;
	
	printf("**ERINSTAGRAM**\n");
	printf("1: Load image\n");
	printf("2: Display image\n");
	printf("3: Edit image\n");
	printf("0:Exit\n\n");
	printf("Choose from one of the options above: ");
	scanf("%d", &choice);
	
	return choiceMenu;
}

int editMenu(){
	int choiceEdit;
	
	printf("**EDITING**\n");
	printf("1: Crop image\n");
	printf("2: Dim image\n");
	printf("3: Brighten image\n");
	printf("0: Return to main menu\n");
	printf("Choose from one of the options above: ");
	scanf("%d", &choiceEdit);
	
	return choice;
}
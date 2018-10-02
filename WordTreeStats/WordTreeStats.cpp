// WordTreeStats.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream.h>
#include <fstream.h>
#include "RBTree.h"
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/*******************************************************************************

   C++ PROJECT      NAME: Frank Giordano
                    Word Parse Tree Analyzer 

Project "Red-Black Tree" is designed to be able to read any ASCII-character
file and sort all the words in the file based on the "ASCII string ordering".
The data structure to be used is a red-black tree. On the output file, reader
can get the list of sorted distinct words along with their number of occurences
and other relevant data.

********************************************************************************/

int Get_Identifier(FILE *fp, char id[]);
int id_count = 0;

int main() {

	char input;
	char identifier[20];
	RBTree *Root, *a;

	FILE *fp = NULL;

	fp = fopen("t3.txt", "r");


	Get_Identifier(fp, identifier);

	Root = new RBTree;
	strcpy(Root->key, identifier);   //first identifier assigned to root
	Root->color = 2;                   //root is black

	while ((input = Get_Identifier(fp, identifier)) != EOF) {            //insert new identifiers read to tree 

		a = new RBTree;
		strcpy(a->key, identifier);
		Root = Root->RB_Insertion(Root, a);
	}

	cout << "You will see the result in result.txt\n";
	fout << "Here is the sorted distinct words read along with their # of occurrences:\n";
	Root->print(Root, treeheight);


	fout << "\n\nTotal # of distinct words is: " << word_count << endl;
	fout << "Total # of word occurences is: " << --id_count << endl;
	fout << "The normal height of the final tree is: " << treeheight << endl;
	Root->Black_Height(Root);
	fout << "Total number of left rotations performed is: " << left_rotate_count << endl;
	fout << "Total number of right rotations performed is: " << right_rotate_count << endl;
	return(0);

}

int Get_Identifier(FILE *fp, char id[]) {
	int i = 0;
	char input;

	id[0] = NULL;
	while (id[0] == NULL) {
		input = fgetc(fp);
		if (input == EOF) {
			printf(" END OF FILE POINTER REACHED\n");
			break;
		}
		while (((input >= 65) && (input <= 90)) || ((input >= 97) && (input <= 122))) {
			id[i] = input;
			i++;
			input = fgetc(fp);
		}

	}
	id[i] = '\0';
	id_count++;
	return (input);
}
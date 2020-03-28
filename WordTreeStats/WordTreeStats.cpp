// WordTreeStats.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <fstream>
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
can get the list of sorted distinct words along with their number of occurrences
and other relevant data.
********************************************************************************/
int Get_Identifier(FILE *fp, char id[]);
int id_count = 0;
int word_count = 1;
int treeheight = 0;
int left_rotate_count = 0;
int right_rotate_count = 0;

std::ofstream fout("result.out");

int main(int argc, char *argv[]) {
    char identifier[20];
    RBTree *Root, *a;
    FILE *fp = NULL;

    if (argc > 2) {
        std::cout << "To many parameters please specify one file name.";
        exit(-1);
    }

    fopen_s(&fp, argv[1], "r");

    if (fp == NULL) {
        std::cout << "Error reading file.";
        exit(-1);
    }

    Get_Identifier(fp, identifier);

    Root = new RBTree;
    strcpy_s(Root->key, identifier);  // first identifier assigned to root
    Root->color = 2;                  // root is black

    while ((Get_Identifier(fp, identifier)) != EOF) { // insert new identifiers read to tree
        a = new RBTree;
        strcpy_s(a->key, identifier);
        Root = Root->RB_Insertion(Root, a);
    }

    std::cout << "Results stored within result.out.\n";
    fout << "List of sorted distinct words and their # of occurrences:\n\n";
    Root->print(Root, treeheight);

    fout << "\n" << word_count << " - distinct words" << std::endl;
    fout << --id_count << " - word duplicates" << std::endl;
    fout << treeheight << " - normal tree height" << std::endl;
    Root->Black_Height(Root);
    fout << left_rotate_count << " - left tree rotations performed" << std::endl;
    fout << right_rotate_count << " - right rotations performed" << std::endl;

    return (0);
}

int Get_Identifier(FILE *fp, char id[]) {
    int i = 0;
    char input;

    id[0] = NULL;
    while (id[0] == NULL) {
        input = fgetc(fp);
        if (input == EOF) {
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
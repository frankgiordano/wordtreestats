# wordtreestats

This was one of my early C++ programs I have written. The goal was to implement a balance binary tree structure (Red Black tree) and demonstrated it. 
This program when executed accepts an argument for specifying a filename for it to process. It will retrieve all the words in the file and adds them in the tree sorted. 
It will then provide results of all the words sorted and the number of occurrences and tree processing stats. The results will be stored in a file called results.out. 

An example:

C:\>wordtreestats input.txt  
Results stored within result.out.

C:\>notepad result.out

result.out:

List of sorted distinct words and their # of occurrences:

A 18  
ABSTRACTS 2  
ACP 1  
AFGI 1  
ANNOUNCEMENT 1  
ASCII 1  
Aarhus 2  
Abelian 3  
Abstraction 1  
Accept 1  
Aceto 1  
Action 2  
Address 6  
...........
...........

1441 - distinct words  
4492 - word duplicates  
13 - normal tree height  
7 - black tree height  
461 - left tree rotations performed  
449 - right rotations performed  


This was one of my early C++ programs I have written. The goal was to implement a balance binary tree structure (Red Black tree) and demostrated it. 
This program when executed looks for input.txt file in the current working directory. It will retrieve all the words in the file and adds them in the tree sorted. 
It will then provide results of all the words sorted and the number of occurances and other stats about the tree and its usage. An example:


Here is the sorted distinct words read along with their # of occurrences:

A 18  ABSTRACTS 2  ACP 1  AFGI 1  ANNOUNCEMENT 1  
ASCII 1  Aarhus 2  Abelian 3  Abstraction 1  Accept 1  
Aceto 1  Action 2  Address 6  Addressing 1  After 1  
...........
...........

Total # of distinct words is: 1441
Total # of word occurences is: 4492
The normal height of the final tree is: 13
Black Height is: 7
Total number of left rotations performed is: 461
Total number of right rotations performed is: 449

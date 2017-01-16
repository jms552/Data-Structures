Julie Salah
Data Structures
Hashing Assignment


For this assignment we had to create a spell checker using a hash table. For my project I used C++, my own linked list class, and the STL vector class. I created the hash tables using the separate chaining method from the text book along with the Horner’s hash function. 

The file that my program read in was “the daag has fouur legs” it returned 3 collisions which means three words were spelled correctly, and 2 misspelled words. My files were read in with an argument and through a file path. 

I loaded my has table with the dictionary then used each word in my text file as the key. It would search the table for the same value and if it found it then the word was spelled correctly, if it inserted without adding on to a list then it was spelled incorrectly. 
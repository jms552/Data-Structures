Julie Salah
Data Structures - Fall 2015
HW0
September 9, 2015
_______________________

For this project we had to create two vector classes, one consisting of linked lists and another of a container based array. The linked lists was standard from what we have done in previous classes however the array class was a challenge for me. It has been awhile since I have messed around with arrays, you had to make a copy and then adjust it how you needed to. I had trouble with shifting the array after I had deleted something from it. I used c++ to implement my code, along with singular linked lists. 

From running the test, obviously as your input size would increase the time would increase. If I were to increase it to 200,00 items I think my final numbers would be double if it were to continue the same trend. You can tell from my table the arrays were slower than the linked lists. That is because everything had to be copied from one array to another. In order to speed up that process, in the erase rear I started to do 2 * the capacity, instead of just increasing the array by one. It sped up the process but still wasn’t as fast as the linked list. 

*Everyone once in awhile when changing the int size to run these times it would stop at the time counter, but if I would just change the time and come back it would work. 

				Vector (Array)				Vector(Linked List)		
Input Size(N)	Insert_front (time)	Insert_back (time)	Insert_front (time)	Insert_back (time)	
500		0.977387 ms		0.59676 ms		0.137772 ms		0.57302 ms	
1,000		3.45647 ms		1.55164 ms		0.241931 ms		2.17594 ms	
50,000		6717.54 ms		3328.75 ms		9.07694 ms		4549.71 ms	
100,000		26554.1 ms		13058.3 ms		18.3549 ms		17952.6 ms	
					

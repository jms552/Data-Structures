Julie Salah
Data Structures - Fall 2015
HW3 - Sorting
October 28, 2015
_____

For this project we had to implement 3 sorting algorithms to the array class we built in the first assignment. I used c++ in this project and ended up building my sorting algorithms main.

I built this project originally with the array in the built in library and when I modified it to use the dynamic array that we built I was surprised to see how much the time tables changed. 

Quick sort was the quickest for me, followed by Radix. The slowest by far was insertion sort. Quick sort became buggy when it got to 800000 and 1000000 items. So for this project I decided to use Radix Sort, Merge Sort and Insertion Sort. 

Below is my run times for the sorting algorithms I implemented:

Input Size	Quick Sort	Radix Sort	Insertion Sort	Merge Sort		T(n) measured	T(n) measured	T(n) measured	T(n) measured10,000		2.677		4.123		339.583		5.47420,000		7.286		7.098		1340.66		9.83940,000		11.718		14.518		5076.38		21.867	80,000		24.139		29.538		20041.5		43.976100,000		33.519		47.137		31557.2		57.839					time is  in miliseconds		
		
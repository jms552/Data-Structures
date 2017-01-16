//
//  main.cpp
//  Sorting
//
//  Created by Julianne Salah on 10/18/15.
//  Copyright (c) 2015 Julianne Salah. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <random>
#include "time.h"
#include "array.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;


//print function
void print(Myarray<int> a, int n)
{
    int i = 0;
    while(i < n){
        std::cout << a[i] << ",";
        i++;
    }
    std::cout << "\n";
}

//****************** INSERTION SORT ****************************************//

void insertionSort (Myarray<int> A, int n)
{
    int i;
    int j;
    int v;
    
    for (i=1; i <= n-1; i++)
    {
        v = A[i];
        j=i;
        while (A[j-1] > v && j >=1)
        {
            A[j] = A[j-1];
            j--;
        }
        A[j] = v;
        
    }
}

//****************** MERGE SORT ****************************************//

void Merge(Myarray<int> A, Myarray<int> temp, int left, int mid, int right)
{
    int i, left_end, size, temp_pos;
    left_end = mid-1;
    temp_pos = left;
    size = right - left +1;
    while ((left <=left_end) && (mid <= right))
    {
        if(A[left] <= A[mid])
        {
            temp[temp_pos] = A[left];
            temp_pos = temp_pos +1;
            left = left + 1;
        }
        else {
            temp[temp_pos] = A[mid];
            temp_pos = temp_pos + 1;
            mid = mid + 1;
        }
    }
    while (left <= left_end)
    {
        temp[temp_pos] = A[left];
        left = left + 1;
        temp_pos = temp_pos + 1;
    }
    while (mid <=right)
    {
        temp[temp_pos] = A[mid];
        mid = mid + 1;
        temp_pos = temp_pos + 1;
    }
    for ( i=0; i <=size; i ++)
    {
        A[right] = temp[right];
        right = right - 1;
    }
}

void MergeSort(Myarray<int> A, Myarray<int> temp, int left, int right)
{
    int mid;
    if(right > left)
    {
        mid = (right + left)/2;
        MergeSort(A, temp, left, mid);
        MergeSort(A, temp, mid+1, right);
        Merge(A, temp, left, mid+1, right);
    }
}

//****************** QUICK SORT ****************************************//
int Partition(Myarray<int> A, int low, int high)
{
    //maybe change pivot spot
    int left, right, pivot_item = A[((low+high)/2)];
    left = low;
    right = high;
    while (left < right)
    {
        //move left while item < pivot
        while (A[left] <= pivot_item && left < 100000)
            left++;
        //move right while item > pivot
        while (A[right] > pivot_item)
            right--;
        if (left < right){
            int temp = A[left];
            A[left] = A[right];
            A[right] = temp;
          }
    }
    A[low] = A[right];
    A[right] = pivot_item;
    return right;
}

void Quicksort (Myarray<int> A, int low, int high)
{
    int pivot;
    //temination condition
    if (high > low)
    {
        pivot = Partition(A, low, high);
        Quicksort(A, low, pivot-1);
        Quicksort(A, pivot+1, high);
    }
}

//****************** COUNTING SORT ****************************************//
void CountingSort (Myarray<int> A, int n, Myarray<int> count,  int k)
{
    int *output=new int[n];
    
    //c is output & B is count
    
    for (int i=0; i < 10; i++)
        count[i] = 0;
    
  
    for (int j=0; j<n; j++)
        count[(A[j]/k)%10] = count[(A[j]/k)%10] + 1;
    //B[i] now contains the number of elements equal to i
    for ( int i=1; i<10; i++)
        count[i] = count[i]+count[i-1];
    //B[i] now contains the number of elements <= i
    for (int j= n-1; j>=0; j--)
    {
        output[count[(A[j]/k)%10]-1] = A[j];
        count[(A[j]/k)%10] = count[(A[j]/k)%10] - 1;
    }
    for (int i = 0; i < n; i++)
    {
        A[i] = output[i];
    }
}

//****************** Radix SORT ****************************************//
// A function to get maximum value in arr[]
int getMax(Myarray<int> A, int n)
{
    int mx = A[0];
    for (int i = 1; i < n; i++)
        if (A[i] > mx)
            mx = A[i];
    return mx;
}

void radixSort(Myarray<int> A, Myarray<int> B, int n)
{
    // Find the maximum number to know number of digits
    int m = getMax(A, n);
    
    // Do counting sort for every digit
    for (int exp = 1; m/exp > 0; exp *= 10)
        CountingSort(A, n, B, exp);
}


//*****************************************************************//

//********************   MAIN   **********************************//

//*****************************************************************//


int main(int argc, const char * argv[])
{
    int size = 80000;
    ProcessTimer stopWatch;
    Myarray<int> arr;
    Myarray<int> temp2;
    //Myarray<int> tmp[10];
    //int tmp[10];
    //int n = sizeof(arr)/sizeof(arr[0]);
    
    // Random seed
    random_device rd;
    
    // Initialize Mersenne Twister
    mt19937 gen(rd());
    
    // Generate random number
    uniform_int_distribution<> dis(1, size);
    
    // Generate pseudo-random numbers
    for (int i = 0; i < size; i++)
    {
        int randomitems = dis(gen);
        arr.insert_front(randomitems);
       // cout << "random number in array: " << arr[i] << endl;
    }
    
   
    cout << "invoking function to sort " << endl;
    stopWatch.setTimeStart(clock());
    Quicksort(arr, 0, (size-1));
    //MergeSort(arr, temp2, 0, (size-1));
    //insertionSort(arr, size);
    //radixSort(arr, temp2, size);
    stopWatch.setTimeEnd(clock());
    print(arr, size);
    cout << stopWatch << endl;
    return 0;
}

//*****************************************************************//
//********************   MAIN   **********************************//
//*****************************************************************//


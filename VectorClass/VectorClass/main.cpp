//
//  main.cpp
//  VectorClass
//
//  Created by Julianne Salah on 9/7/15.
//  Copyright (c) 2015 Julianne Salah. All rights reserved.
//


#include <iostream>
#include <chrono>
#include <random>
#include "LL.h"
#include "array.h"



using namespace std;



int main(int argc, const char * argv[])
{


cout << "steady_clock" << endl;
cout << chrono::steady_clock::period::num << endl;
cout << chrono::steady_clock::period::den << endl;
cout << "steady = " << boolalpha << chrono::steady_clock::is_steady << endl << endl;

    
auto start = chrono::steady_clock::now();


//code to be timed
    
    LL<int> myVector;
    //Myarray<int> myVector;
    
    int size = 500;
 //
    // Random seed
    random_device rd;
    
    // Initialize Mersenne Twister
    mt19937 gen(rd());
    
    // Generate random number
    uniform_int_distribution<> dis(1, size);
    
    // Generate ten pseudo-random numbers
    for (int i = 0; i < size; i++)
    {
        int randomitems = dis(gen);
        //cout << "\nRandom X = " << randomitems;
        myVector.insert_rear(randomitems);
        
    }


auto end = chrono::steady_clock::now();

// Store the time difference between start and end
auto diff = end - start;
cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
    
return 0;

}

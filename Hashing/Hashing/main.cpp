//
//  main.cpp
//  Hashing
//
//  Created by Julianne Salah on 11/1/15.
//  Copyright (c) 2015 Julianne Salah. All rights reserved.
//

#include "hash.h"
#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <exception>
#include <cctype>
#include <algorithm>
#include <cstring>

using namespace std;

void loadData(HashTable<string>&, string);



int main(int argc, const char * argv[])
{
    
    try
    {
        
        if (argc < 2)
        {
            
            string errorMessage = "Please pass input data file name as a cmd. line argument.";
            //std::cout << "caught it: \"" <<  "\"" << endl;
            throw errorMessage;
        }
        else
        {
            string inputDataFileName = argv[2];
            
            HashTable<string> table;
            
            cout << "Calling function loadData() " << endl;
            
            loadData(table, inputDataFileName);
            //each element is an instance  -
            //containing all of the values from one row
            
             cout << "Function loadData() returned control to main() " << endl;
        
            
           
           // int countMisspelled = 0;

            
        //Get input from textfil.txt
            string word;
            ifstream input;
            input.open("/Users/JulieSalah1/Desktop/textfile.txt");
            
        //File checking
            if (input.fail())
            {
                cout << "File does not exist" << endl;
                cout << "Exit program" << endl;
            }
            
    
     
        while( getline(input, word))
            {
      
               
                Node<string> insertWord(word);
                
                insertWord = word;
               
                insertWord = word.substr(0, word.find(" "));
                
               
                
                Node<string> *addword = new Node<string>(insertWord);
                
                
                
               
                
          //If a word is not in the dictionary assume misspelled
                
                (table.spellcheck(addword));
               
             }
            
        input.close();
            
        cout << endl;

            
            cout << "Number of misspelled words : " << table.theMisspelling() << endl;
            cout << "line number the misspelled word occurred on: " << "" << endl;
            cout << "number of collisions in creating the hash table: " << table.theCollisions() << endl;
            cout << "size of hash table: " << table.tableSize() << endl;
        
        }
        
        
    }//end of try block
    
    //catch block
    catch (string strError)
    {
        cout << "Inside main\n";
        throw strError;
        
    }
 
}



//*************************************************************************************
//*************************    LOAD THE FILE     **************************************
//*************************************************************************************


void loadData(HashTable<string> &table, string mFileName)
{
    cout << "Inside function loadData() " << endl;
    try
    {
        int recordsAccordingToFile = 0;
        string commentsToIgnore = "";
        string oneLine = "";
        string fileOpenError = "";
        ifstream inFile(mFileName.c_str());
        
        if (!inFile)
        {
            inFile.close();
            fileOpenError = "Input file containing data: ";
            fileOpenError += mFileName;
            fileOpenError += " failed to open.";
            throw fileOpenError;
        }
        else
        {
            
            inFile >> recordsAccordingToFile;
            getline(inFile, oneLine);
            

            cout << commentsToIgnore << endl;
            
            while ( getline(inFile, oneLine) )
            {
                
                Node<string> Word(oneLine);
                cout << &Word << endl;
                
                Word = oneLine.substr(0, oneLine.find("/"));
                
                Node<string> *addword = new Node<string>(Word);
                
                
                
              //loading dictionary into hash table
               table.insertTableitems(addword);
                
            }
            
            cout << "finished reading file data..." << endl;
            
            
            
            cout << "finished loading all data\n";
            
            cout << endl;
            
            inFile.close();
        }
        
        cout << "Exiting function loadData() " << endl;
    }
    
    catch(string sErr)
    {
        cout << "error in loadData function\n";
        cout << sErr << endl;
        
        //throw sErr;
    }
    
}//END function loadData

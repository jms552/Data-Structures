//
//  main.cpp
//  Binary Tree Search
//
//  Created by Julianne Salah on 11/21/15.
//  Copyright (c) 2015 Julianne Salah. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include "Btree.h"

using namespace std;



int main(int argc, const char * argv[])
{
    
std::string input;
std::string inputdata;
std::ifstream inputfile;
std::ifstream datafile;
inputfile.open(("/Users/JulieSalah1/Desktop/command1.txt"));

BinaryTree<INT> TestTree;
    
        while(inputfile>>input)
            {
                if(input == "L:"|| input == "l:")
                    {
                        inputfile >> inputdata;
                        datafile.open(inputdata.c_str());
                        int loadkeys;
                        while(datafile>>loadkeys)
                        {
                            INT * temp = new INT(loadkeys);
                            TestTree.Insert(*temp);

                        }
                    }
    
                if(input == "A:"|| input == "a:")
                    {
                        inputfile >> inputdata;
                        INT * Insertkeys = new INT((atoi(inputdata.c_str())));
                        TestTree.Insert(*Insertkeys);
                        
                    }

                else if(input == "D:"|| input == "d:")
                    {
                        inputfile >> inputdata;
                        INT * ToDelete = new INT((atoi(inputdata.c_str())));
                        TestTree.Insert(*ToDelete);
                    
                        
                    }
    
                if (input == "P1:" || input == "p1:")
                {
                    TestTree.printInorderTraversal();
                    std::cout << "" << std::endl;
                }
                if (input == "P2:" || input == "p2:")
                {
                    TestTree.printPreorderTraversal();
                    std::cout << "" << std::endl;
                }
                if (input == "P3:" || input == "p3:")
                {
                    TestTree.printPostorderTraversal();
                    std::cout << "" << std::endl;
                }

                else if(input == "S:"|| input == "s:")
                    {
                       
                        inputfile >> inputdata;
                        INT * Search = new INT((atoi(inputdata.c_str())));
                        TestTree.findpublic(*Search);

                    }

                if(input == "T:"|| input == "t:")
                {
                    std::cout << "Quit" << std::endl;
                }
        
    }
}


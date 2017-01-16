//
//  hash.h
//  Hashing
//
//  Created by Julianne Salah on 11/6/15.
//  Copyright (c) 2015 Julianne Salah. All rights reserved.
//

#ifndef Hashing_hash_h
#define Hashing_hash_h

#include "LL.h"
#include <iostream>
#include <vector>


using namespace std;

int nextPrime( int n );
int hash(const string & key);



//***************************************************************
//*********************  HASH TABLE  ****************************
//***************************************************************

template<typename T>
class HashTable
{
private:
    vector<LL<T> > theLists;
    //LL<T> *theLists;
  
    int currentSize;
    int collisions = 0;
    int misspelling = 0;
    
//    //****** my hash *********//
//int myhash(const T& x) const
//    {
//        //int hashVal = hash(x);
//        int hashVal = 0;
//        
//        hashVal %= theLists.size();
//        if (hashVal < 0)
//            hashVal += theLists.size();
//        
//        return hashVal;
//        
//    }

    //***************************************************************
    //**************  Horner's Hash Function  ***********************
    //***************************************************************
 public:
    
    int myhash(const string& key )
    {
        int tablesize = 77773;
        int hashVal = 0;
        for (int i = 0; i < key.length(); i++)
            hashVal = 37 * hashVal + key[i];
        
        hashVal %= tablesize;
        if (hashVal <0)
            hashVal += tablesize;
        
        return hashVal;
    }

    

    explicit HashTable( int size = 101 ) : currentSize( 77773 )
    {
        theLists.resize( 101 );
    }
   
int tableSize() const
    {
        return currentSize;
    }

void makeEmpty()
    {
        for (int i= 0; i < theLists.size(); i++)
            theLists[i].clear();
    }
    
bool contains( const T& x) const
    {
        const LL<T> &whichList = theLists[myhash(x)];
        return find(whichList.begin(), whichList.end(), x) != whichList.end();
        
    }
    
bool insert(const T& x )
    {
        LL<T> &whichList = theLists[myhash(x)];
        if( find( whichList.begin( ), whichList.end( ), x ) != whichList.end( ) )
            return false;
        whichList.insert_rear(x);
        
       
    }
    
    
bool remove( const T & x )
    {
        LL<T> & whichList = theLists[myhash(x)];
        LL_iterator<T> itr = find( whichList.begin( ), whichList.end( ), x );
        
        if( itr == whichList.end( ) )
            return false;
        
        whichList.erase(itr);
        --currentSize;
        return true;
    }


void insertTableitems(Node<T> * newItem)
    {
    //inserting items into list but not checking for misspelled words yet
        unsigned int key;
        key = myhash(newItem->info);
        
        Node<T> * current;
       
        
        if (theLists[key].count == 0)
        {
            theLists[key].insert_front(newItem->info);
        }
        else
        {
            
            current = theLists[key].head;
            int i = 1;
            while (i <= theLists[key].count && current->info != newItem->info)
            {
                i++;
                current = current->next;
                theLists[key].insert_front(newItem->info);
                
            }
            
        }
    }
    
    
void spellcheck(Node<T> * newItem)
    {
        //cout << "Hash Table insert Function" << endl;
        
        unsigned int key;
        key = myhash(newItem->info);
        
        Node<T> * current;
        
        {
            
        
        if (theLists[key].count == 0)
        {
            //cout << newItem->info << " has been added to the list." << endl;
            theLists[key].insert_front(newItem->info);
            //misspelling++;
        }
        else
        {
            
            current = theLists[key].head;
            int i = 1;
            while (i <= theLists[key].count && current->info != newItem->info)
            {
                i++;
                current = current->next;
            
            if (current->info == newItem->info)
            {
                cout << newItem->info << " already exists in the Hash Table" << endl;
                cout << "word is spelled correctly!" << endl;
                collisions++;
            }
            else
            {
                //misspelled word
                theLists[key].insert_front(newItem->info);
                misspelling++;
                
            }
                }
            
        }
    }
    }

int theCollisions() const
    {
        return collisions;
    }
int theMisspelling () const
    {
        return misspelling;
    }

bool SearchItem(Node<T> * Item)
{


    Node<T> *current;
    
    unsigned int key;
    key = myhash(Item->info);
    
    while (current->next != NULL)
    {
        if (current->info == Item->info)
        {
            cout<< current->info << " " << endl;
    return true;
            cout << "spelled the word correctly!" << endl;
        }
        
    
        
    else
    {
        
        cout << "spelled the word wrong! Please check the dictionary" << endl;
   }
    }
    return false;
    
}
    

    
};

#endif

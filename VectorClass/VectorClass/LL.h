/*
 *  LL.h
 *
 */

#ifndef LL_h
#define LL_h
#include <iostream>
#include <string>

using namespace std;


//**** Class Template Node*******//

template <typename T>
class Node
{
public:
    T info;
    Node<T> *next;
    
    Node(T, Node<T> *next = NULL);
    //construction in node class
};

//End class template Node


//**** Class Template LL*******//
template<typename T>
class LL
{
private:
    int count;
    Node<T> *head;
    Node<T> *tail;
    
    
    
public:
    LL();
    //constructor without parameters
    
    LL(const LL<T> &otherLL);
    //copy constructor
    
    ~LL();
    //deconstructor - calls clear function
    
    void insert_rear(T);
    //push back function called in mine log builds mines
    
    void insert_front(T);
    //push front function - tested in place of push_back
    
    void insert(T);
    //inserts node at index
    
    void erase_front(T);
    //deletes front node
    
    int getfront (){ return head->info;}
    //returns the head
    
    int getback (){ return tail->info;}
    //returns the tail
    
    void eraseIndex(int);
    //deletes node at index
    
    void erase_back(T);
    //pop back - deletes last node in the list
    
    void clear();
    //clears the list
    
    int size () const;
    //set size returns count integer

    
    T& at(int ndx) const;
    //at function const sets the bounds
    
    T& operator[] (int ndx) const;
    //[] operator function const
    //calls the at function
    
    //no capacity for the linked list

};
//end class template LL



//Node constructor
template <typename T>
Node<T>::Node(T inf, Node<T> *ptr)
{
    info = inf;
    next = ptr;
}//end Node


//constructor without parameters
template <typename T>
LL<T>::LL()
{
    head = NULL;
    count = 0;
    tail = NULL;
}
//end LL::LL



//clear function LL - clears the list
template <typename T>
void LL<T>::clear()
{
    if (head == NULL)
    {
        //empty because already clear
    }
    
    else
    {
        Node<T> *current = head;
        int deleteCount = 0;
        while (current != NULL)
        {
            head = head->next;
            delete current;
            deleteCount++;
            current = head;
        }
        
    }
    
}//end clear function

//LL deconstructor
template <typename T>
LL<T>::~LL()
{
    //cout << "Entered destructor LL::~LL()" << endl;
    
    clear();
    
    //cout << "Exiting destructor LL::~LL()" << endl;
    
} //END LL::~LL()

//LL push back function
template <typename T>
void LL<T>::insert_rear(T t0)
{
    try
    {

    Node<T> *addMe = new Node<T>(t0);
    
    if (head == NULL)
    {
        
        head = addMe;
        addMe->next = NULL;
    }
    else
    {
        Node<T> *current = head;
        
        while (current->next != NULL)
        {
            current = current->next;
        }
        
        current->next = addMe;
        addMe->next = NULL;
    }
        count++;
    
    }
    catch (std::bad_alloc bA)
    {
        std::cout << "Error allocating Memory" << endl;
        std::cout << bA.what() << endl;
        throw;
    }
    
    
} //END LL::push_back()


//LL size function
template<typename T>
int LL<T>::size () const
{
    return count;

}//end size function

//LL push front function
template <typename T>
void LL<T>::insert_front(T t0)
{
    try {
    
    Node<T> *addMe = new Node<T>(t0);
    
    if (head == NULL)
    {
        head = addMe;
        addMe->next = NULL;
    }
    else
    {
        
    addMe->next = head;
    head = addMe;
        
    }
    }
    catch (std::bad_alloc bA)
    {
        std::cout << "Error allocating Memory" << endl;
        std::cout << bA.what() << endl;
        throw;
    }
    
    //count++;
    
} //END LL::push_front()

template <typename T>
void LL<T>::insert(T t0)
{
    if (index > count-1 || index < 0)
    {
        std::cout << "Your index WRONG"<< std::endl;
    }
    else
    {
            Node<T> *addMe = new Node<T>(t0);
            Node<T> *current = head->next;
            Node<T> *previous = head;
            
            int temp = 0;
            
            if (head == NULL)
            {
                head = addMe;
                addMe->next = NULL;
            }
            else
            {
                while (previous->next != tail)
                {
                    previous = current;
                    current = current->next;
                    temp++;
                    
                    if (current == tail)
                    {
                        current -> next = addMe;
                        addMe -> next = NULL;
                       
                    }
                    else if (current == index)
                    {
                        previous->next = addMe;
                        addMe->next = current;
                    }
                }
            }
        
        }

    
}//END insert


//LL pop_back function
template <typename T>
void LL<T>::erase_back(T)
{
    Node<T> *current = head;
    
if(current == NULL)
{
    //do nothing list is empty
}
else if (current == tail)
{
    delete current;
}
else
{
while(current->next != tail)
{
    current = current->next;
}
delete tail;
tail = current;
}

}//end pop_back


//LL pop_back function
template <typename T>
void LL<T>::eraseIndex(int index)
{
    if (index > count-1 || index < 0)
    {
      //wrong index
    }
    else
    {
        Node<T> *current = head->next;
        Node<T> *previous = head;
        
        int temp = 0;
        
        if (head == NULL)
        {
            //empty list
        }
        else
        {
            while (previous->next != tail && temp != index)
            {
                previous = current;
                current = current->next;
                temp++;
                
                if (current == tail)
                {
                    delete current -> next;
                    current = tail;

                }
                else if (current == index)
                {
                    delete previous->next;
                    previous->next= current->next;
                    current = current->next;

                }
            }
        }

    }
}//end erase index



template <typename T>
void LL<T>::erase_front(T)
{
    Node<T> *current = head;
    
    if(current == NULL)
    {
        //do nothing list is empty
    }
    else if (current == head)
    {
        delete current;
    }
    else
    {
        while(current->next != head)
        {
            current = current->next;
        }
        delete head;
        head = current;
    }
    
}




//LL at function const
template <typename T>
T& LL<T>::at(int ndx) const
{
    string errorIII = "bounds checking";
    try
    {
        if (ndx >= size())
        {
            throw errorIII;
        }
        
        else
        {
            Node<T> *current = head;
            for (int i = 0; i < ndx; i++)
            {
                current = current -> next;
            }
            return current -> info;
        }
    }
    
    catch (string)
    {
        cout << "Out of Range" << endl;
        throw errorIII;
    }
}//end at function const

//overloaded [] function const
template <typename T>
T& LL<T>::operator[](int ndx) const
    {
        return this->at(ndx);
    }
//end overloaded [] function const




#endif

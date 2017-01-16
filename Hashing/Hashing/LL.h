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
    string key;
    Node<T> *next;
//    
//    Node()
//    {
//        next = NULL;
//    };
    
    Node (T,  Node <T>* = NULL);
    //construction in node class
};

//Node constructor
template <typename T>
Node<T>::Node(T info, Node<T> *ptr)
{
    //this->info = info;
    next = ptr;

}//end Node

//End class template Node


///iterators/////
template <typename T>
class LL_iterator
{
    
public:
    
    Node<T> *current;
    //pointer to point to the current
    //node in the linked list

    
    LL_iterator();
    //default constructor
    //Postcondition: current = NULL;
    
    LL_iterator(Node<T> *ptr);
    //constructor with parameter
    //Postcondition: current = ptr;
    
    T& operator*();
    //overloaded dereferencing operator *
    //Postcondition: Returns the info contained in the node
    
    
    LL_iterator operator++();
    //overloaded pre-increment operator
    //Postcondition: The iterator is advanced to the next node in the linked list
    
    bool operator==(const LL_iterator &rhsObj) const;
    //overloaded equality operator
    //Postcondition: Returns true if this iterator is equal to the
    //               iterator specified on the right hand side
    //               otherwise returns false
    
    bool operator!=(const LL_iterator &rhsObj) const;
    //overloaded equality operator
    //Postcondition: Returns true if this iterator is NOT equal to the
    //               iterator specified on the right hand side
    //               otherwise returns false
    
    
}; //END class LL_iterator

//**** Class Template LL*******//
template<typename T>
class LL
{
public:
    int count;
    Node<T> *head;
    Node<T> *tail;
    

    LL();
    //constructor without parameters
    
    LL(const LL<T> &otherLL){
        //copy constructor
    };
    //copy constructor
    
    ~LL();
    //deconstructor - calls clear function
    
    void insert_rear(T);
    //push back function called in mine log builds mines
    
    void insert_front(T);
    //push front function - tested in place of push_back
    
    void insert(T);
    //inserts node at index
    
    //remove item
    bool removeItem( T itemKey );
    
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
    
    int Length(Node<T> head)
    {
        Node<T> *current  = head;
        int count = 0;
        while (current != NULL) {
            count++;
            current = current->next;
        }
        return count;
    };
    
void resize(int newSize)
    {
        
        if (newSize > size())
           // newSize * 2 +1;
            
        size() = newSize;
    };
    


    T& at(int ndx) const;
    //at function const sets the bounds
    
    T& operator[] (int ndx) const;
    //[] operator function const
    //calls the at function
    
    //no capacity for the linked list
    
    LL_iterator<T> begin();
    LL_iterator<T> end();
    
    LL_iterator<T> begin() const;
    LL_iterator<T> end() const;
    
    void erase(LL_iterator<T>& itr);
    
};
//end class template LL



/****************************************************************************
 *                                                                          *
 *               class LL_iterator implementation code                      *
 *                                                                          *
 ****************************************************************************/
//LL_iterator constructor
template <typename T>
LL_iterator<T>::LL_iterator()
{
    current = NULL;
}//end

//LL_iterator constructor
template <typename T>
LL_iterator<T>::LL_iterator(Node<T> *ptr)
{
    current = ptr;
}//end

//LL_iterator * operator
template <typename T>
T& LL_iterator<T>::operator*()
{
    try
    {
        if (current == NULL)
        {
            throw string("iterator at end");
        }
        
    }
    catch (string sErr)
    {
        throw sErr;
    }
    
    return current->info;
} //LL_iterator * operator end

//LL_iterator increment operator
template <typename T>
LL_iterator<T> LL_iterator<T>::operator++()
{
    try
    {
        if (current == NULL)
        {
            throw string("iterator already at end, cannot increment.");
        }
        
        current = current->next;
    }
    
    catch (string sErr)
    {
        throw sErr;
    }
    
    return *this;
}//LL_iterator end

//LL_iterator == operator
template <typename T>
bool LL_iterator<T>::operator==(const LL_iterator &rhsObj) const
{
    return this->current == rhsObj.current;
}//LL_iterator == operator end

//LL_iterator!= operator
template <typename T>
bool LL_iterator<T>::operator!=(const LL_iterator &rhsObj) const
{
    return this->current != rhsObj.current;
}//LL_iterator!= operator end

template <typename T>
LL_iterator<T> LL<T>::begin()
{
    LL_iterator<T> temp(head); //pass head to the constructor
    
    return temp;
}

//end function
template <typename T>
LL_iterator<T> LL<T>::end()
{
    LL_iterator<T> temp(NULL); //pass NULL to the constructor or tail->next
    
    return temp;
}

template <typename T>
LL_iterator<T> LL<T>::begin() const
{
    LL_iterator<T> temp(head); //pass head to the constructor
    
    return temp;
}

//end function
template <typename T>
LL_iterator<T> LL<T>::end() const
{
    LL_iterator<T> temp(NULL); //pass NULL to the constructor or tail->next
    
    return temp;
}

/****************************************************************************
 *                                                                          *
 *               class Node implementation code                      *
 *                                                                          *
 ****************************************************************************/




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
    Node<T> *current = head;
    
    if (head == NULL)
    {
        //empty because already clear
    }
    
  while (current != NULL)
        {
            head = head->next;
            delete current;
            current = head;
        }
    
    //current->next  = NULL;
    //current->prev = NULL;
    
    tail = head = NULL;


}//end clear function

//LL deconstructor
template <typename T>
LL<T>::~LL()
{
    clear();
  
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

template <typename T>
void LL<T>::erase(LL_iterator<T>& itr)
{
    Node<T> *current = head;
    Node<T> *p = itr.current;
    if (current == NULL)
        return; //do nothing list is empty
    
    LL_iterator<T> retVal(p->next);
    p->prev->next = p->next;
    p->next->prev = p->prev;
    
    delete p;
    
    count--;
    
    
}



#endif

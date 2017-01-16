#ifndef array_h
#define array_h

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

using namespace std;

//**** Class Template Node*******//
template <typename T>
class Myarray
{
private:
    int index;
    int capacity;
    T *objects;
    T *temp;
    
    
public:
    
    Myarray();
    //contructors
    Myarray(T, int);
    
    ~Myarray();
    //deconstructor

    //functions that increase/decrease items in array
    void insert_rear(T);
    //inserts an item in the back
    
    void insert_front(T);
    //inserts an item in the front
    
    void eraseIndex(int);
    //erases an item at the index
    
    void insert(int, T);
    //inserts an item at index
    
    void erase_back();
    //erases items starting in the back
    
    void erase_front();
    //erases items starting in the fron
    
    //Accessors:
    int size() const;
    //returns the size
    
    int getCapacity() const;
    //returns the capacity
    
    int getFront();
    //returns the front item
    
    int getBack();
    //returns the last item
    
    T& operator[](int);
    //[] operator function
    
    const T& operator[](int) const;
    ////[] operator function const
   
    T at(int) const;
    //at function
    
};
//**** End of Class Template Node*******//


//**** Implementation *******//

template<typename T>
Myarray<T>::Myarray()
{
    capacity = 1;
    index = 0;
    objects = new T[capacity];
    temp = NULL;
}

template<typename T>
Myarray<T>::Myarray(T t0, int size)
{
    capacity = 1;
    index = 0;
    objects = new T[capacity];
    temp = NULL;
}

template<typename T>
T& Myarray<T>::operator[](int i)
    {
        if (i < 0 || i >= index)
       
        {
            //std::cout << "Invalid index\n" << std::endl;
        }
        
        return objects[i];
    }

template<typename T>
const T& Myarray<T>::operator[](int i) const
{
    if (i < 0 || i >= index)
    {
       // std::cout << "Invalid index\n" << std::endl;
    }
    
    return objects[i];
}





template<typename T>
void Myarray<T>::erase_back()
{
    if(index > 0)
        index--;
    
    for (int i = index-1; i>=0; i--)
    {
        objects[i] = objects[i];
    }
    
    objects = temp;
}

    
template<typename T>
void Myarray<T>::erase_front()
{
    if(index > 0)
        index--;
    
    for (int i = 0; i < index; i++)
    {
        objects[i] = objects[i+1];
    }
    
    objects = temp;
    
}


template<typename T>
T Myarray<T>::at(int i) const
    {
        string error = "Error out of bounds";
        
        try
        {
//            
//            if (i >= index())
//            {
//                throw error;
//            }
//            return at(index);
            if (i < 0 || i >= index)
            {
                std::cout << "Invalid index at function\n" << std::endl;
            }
            
            return objects[i];
            
        }
        
        catch (string)
        {
            cout << "Out of Range" << endl;
            throw error;
        }
    }



template <typename T>
void Myarray<T>::insert_rear(T t0)
{

        capacity = (2 * capacity);
        objects = new T [capacity];
    
    for (int i = 0; i < capacity; i++)
    {
        objects[i] = temp[i];
    }
    
    
    delete[] objects;
    temp = objects;
    objects[index++] = t0;
    
}

template<typename T>
void Myarray<T>::eraseIndex(int i)
{
    for (int j = i; j < index; j++)
    {
        objects[i] = objects[i+1];
    }
    
    index--;
}



template <typename T>
void Myarray<T>::insert_front(T t0)
{
    temp = new T[capacity + 1];
    temp[0] = t0;
    for (int i = 0; i < capacity; i++)
    {
        temp[i + 1] = objects[i];
    }
    capacity = capacity + 1;
    delete[] objects;
    objects = new T[capacity];
    for (int i = 0; i < capacity; i++)
    {
        objects[i] = temp[i];
    }
    delete[] temp;
};//END insert_front


template<typename T>
void Myarray<T>::insert(int i, T t0)
{
    if (index >= capacity)
    {
        capacity = (2 * capacity);
        temp = new T [capacity];
    }
    
    int j = index-1;
    for(; j > 0 && objects[j-1]; --j)
    {
        objects[j] = objects[j-1];
    }
    
    objects[j]=t0;
    index++;
}

template<typename T>
int Myarray<T>::size() const
{
    return index;
}

template<typename T>
int Myarray<T>::getCapacity() const
{
    return capacity;
}

template<typename T>
int Myarray<T>::getFront()
{
    return objects[0];
}

template<typename T>
int Myarray<T>::getBack()
{
    return objects[index-1];
}

template<typename T>
Myarray<T>::~Myarray()
{
//deconstructor
}

#endif







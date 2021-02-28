//implementation file for stack
//caleb gibson

#include "arrayStack.hpp"

//constructor
template <typename T>
arrayStack<T>::arrayStack()
{
    //set size = 1
    stackLength = 1;
    arrPoint = new T [stackLength]; //create a dynamically allocated array of inital size
    //set flags
    h = 0;
    //initialize k to -1
    k = -1;
}

//destructor
template <typename T>
~arrayStack<T>::arrayStack()
{
    //free memory
    delete [] arrPoint;
}

//push
template <typename T>
void arrayStack<T>::push(T &val)
{
    //check if array needs to be resized
    resize(); //automatically checks to see if the array needs to be resized and does it
    //insert item at the last spot in array
    arrPoint[usedSpace()] = val;
    usedSpace++;
}

//pop -- returns item to show what was removed
template <typename T>
T arrayStack<T>::pop()
{
    resize(); //check for resize
    T tempPlaceholder = arrPoint[usedSpace()];
    //need to create a temp pointer, copy all values minus 1
    T * tempPoint = new T [usedSpace-1]; 
    for(std::size_t i = 0; i <usedSpace; i++)
    {
        tempPoint[i] = arrPoint[i];
    }
    delete [] arrPoint; //frees memory so we can reassign values
    for(std::size_t j = 0; j <= stackSize; j++) // up to stack size to retain stack size
    {
        arrPoint[j] = tempPoint[j];
    }
    //free temp
    delete [] tempPoint;

    //decrease size
    usedSpace--;
    return tempPlaceholder;
}

//peek -- returns item but does not remove
template <typename T>
T arrayStack<T>::peek()
{
    //return the value of the array at the last index
    return arrPoint[usedSpace()];
}

//is empty
template <typename T>
bool arrayStack<T>::isEmpty()
{
    if(usedSpace() == 0)
    {
        return true;
    }
  return false;
}

//return size 
template <typename T>
std::size_t arrayStack<T>::size()
{
    return stackLength;
}

//return the used space
template <typename T>
std::size_t arrayStack<T>::usedSpace()
{
    return usedSpace;
}

//set the flag H
template <typename T>
void arrayStack<T>::setH(bool &choice)
{
    if(choice == 1)
    {
        return true;
    }
    return false;
}

//set K
template <typename T>
void setK(int &set)
{
    k = set;
}

//resize function
template <typename T>
void arrayStack <T>:: resize()
{
    //check to see if k is positive and H is not asserted
    //incrementing value
    int kAdd = 3;
    if(k > 0 && h == 0)
    {
        if(stackLength == usedSpace) //stack is full
        //resize array based on 3k..5k..7k  
        //create tempPointer
        
        T * tempPoint = new T [size() + (kAdd * k)];
        //copy all values
        for(std::size_t i = 0; i <(size()); i++)
        {
            tempPoint[i] = arrPoint[i]; //loop through all values of arrPoint
        }
        //update stackLength
        stackLength = size() + (kAdd * k);
        //free arrPoint
        delete [] arrPoint;
        //remake
        arrPoint = new T [size()];
        //reassign new sized array
        for(std::size_t a = 0; a < size(); a++)
        {
            arrPoint[a] = tempPoint[a];
        }
        //increase kAdd by two
        kAdd += 2;
        //delete tempPoint
        delete [] tempPoint;
    }
    
    //check to see of the array needs to be resized
    if(stackLength == usedSpace || (h == 1 & usedSpace > stackLength/2))
    {
        //array needs to double
        //create a temp pointer
        T *tempPointer = new T [size() * 2]; //creates a temp
        //pointer to an array twice the size of the original
        for(std::size_t i = 0; i<=size(); i++)
        {
            //assign all values from old pointer to new
            tempPointer[i] = arrPoint[i];
        }
        //delete old pointer
        delete []  arrPoint;
        //recopy values into new arrPoint
        stackLength = 2 * stackLength; // increase size of stack
        arrPoint = new T[stackLength];
        for(std::size_t j = 0; j <= size(); j++)
        {
            arrPoint[j] = tempPointer[j]; //copy into resized array
        }
        //free memory
        delete [] tempPointer;

        if(usedSpace <stackLength/2 && stackLength > 1)
        {
            //do the same thing but now halve the array
            T *tempPoint = new T [size() / 2];
            for(std::size_t x = 0; x <= size()/2; x++)
            {
                tempPoint[x] = arrPoint[x];
            }
            //free memory
            //change size of stack
            stackLength = stackLength / 2;
            delete [] arrPoint;
            //remake arrPoint
            arrPoint = new T [stackLength];
            //copy all values back
            for(std::size_t y = 0; y <= stackLength; y++)
            {
                arrPoint[y] = tempPoint[y];
            }
            //free temp Point
            delete [] tempPoint;
        }

    }
}
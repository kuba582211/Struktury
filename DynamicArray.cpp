#include <iostream>
#include "DynamicArray.h"
using namespace std;


DynamicArray::DynamicArray()
{
    maxSize = 2;
    currentSize = 0;
    array = new int[maxSize];
}
void DynamicArray::addElement(int element)
{
    if (currentSize == maxSize)
        growArray();
    array[currentSize] = element;
    currentSize++;
}
void DynamicArray::addElement(int element, int index)
{
    if (index > currentSize)
    {
        cout << "Invalid index!\n";
        return;
    }
    if (currentSize == maxSize)
        growArray();
    for (int i = currentSize-1; i >= index; i--)
    {
        array[i + 1] = array[i];
    }
    array[index] = element;
    currentSize++;
}
int DynamicArray::findElement(int element)
{
    for (int i = 0; i < currentSize; i++)
    {
        if (array[i] == element)
        {
            //cout << "Element " << element << " is at index " << i << ".\n";
            return i;
        }
    }
    return -1;
}
void DynamicArray::removeElement(int index)
{
    if (index >= currentSize or index < 0)
    {
        cout << "Invalid index!\n";
        cout << currentSize << maxSize;
        return;
    }
    for (int i = index; i < currentSize; i++)
    {
        array[i] = array[i + 1];
    }
    currentSize--;
}
void DynamicArray::growArray()
{
    int* buffer = new int[maxSize];
    for (int i = 0; i < currentSize; i++)
        buffer[i] = array[i];
    maxSize = 2 * maxSize;
    delete[] array;
    array = new int[maxSize];
    for (int i = 0; i < currentSize; i++)
        array[i] = buffer[i];
    delete[] buffer;
}
void DynamicArray::display()
{
    for (int i = 0; i < currentSize; i++)
    {
        if (i)
            cout << ", ";
        cout << array[i];
    }
}

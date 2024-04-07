#pragma once
#include <iostream>
using namespace std;

struct Link
{
    int value;
    Link* next;
    Link()
    {
        value = 0;
        next = NULL;
    }
    Link(int element)
    {
        this->value = element;
        this->next = NULL;
    }
};

struct LinkedList
{
    Link* head;
    LinkedList() { head = NULL; }
    void addLink(int element);
    void addLinkAfter(int element, int after);
    void addLinkAtStart(int element);
    void removeLink(int index);
    int findElement(int value);
    void display();
};

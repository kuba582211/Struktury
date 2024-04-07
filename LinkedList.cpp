#include "LinkedList.h"

void LinkedList::addLink(int element)
{
    Link* newLink = new Link(element);
    if (head == NULL) {
        head = newLink;
        return;
    }

    Link* temp = head;
    while (temp->next != NULL) {

        temp = temp->next;
    }

    temp->next = newLink;
}
void LinkedList::addLinkAfter(int element, int after)
{
    Link* newLink = new Link(element);
    if (head == NULL) {
        head = newLink;
        return;
    }

    Link* temp = head;
    for(int i = 0; i < after; i++)
        temp = temp->next;
    newLink->next = temp->next;
    temp->next = newLink;
}
void LinkedList::addLinkAtStart(int element)
{
    Link* newLink = new Link(element);
    if (head == NULL) {
        head = newLink;
        return;
    }
    newLink->next = head;
    head = newLink;
}
void LinkedList::removeLink(int index)
{
    if (index == 0)
    {
        Link* toDelete = head;
        head = toDelete->next;
        delete toDelete;
        return;
    }
    Link* temp = head;
    for (int i = 1; i < index; i++)

    {
        if (temp->next == NULL)
        {
            cout << "Invalid index";
            return;
        }
        temp = temp->next;
    }
    Link* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
}
int LinkedList::findElement(int value)
{
    Link* temp = head;
    int index = 0;
    while (temp != NULL)
    {
        if (temp->value == value)
        {
            return value;
        }
        temp = temp->next;
        index++;
    }
    return -1;
}
void LinkedList::display()
{
    Link* temp = head;
    if (head == NULL)
    {
        cout << "List empty" << endl;
        return;
    }
    while (temp != NULL)
    {
        cout << temp->value << ", ";
        temp = temp->next;
    }
}

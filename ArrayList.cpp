/**
 * An extensible circularly-linked array list implementation.
 * @author ketsubetsu
 * <pre>
 * File: ArrayList.cpp
 * </pre>
 */

#include <iostream>
#include <cassert>
#include <string>
#include "ArrayList.h"

using namespace std;

template <typename U>
template <typename T>
ArrayList<U>::Node<T>::Node(T element)
{
    data=element;
    next=nullptr;
}

template <typename T>
ArrayList<T>::ArrayList()
{
    rear=nullptr;
    length=0;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& rhs)
{
    rear=nullptr;
    length=0;
    if(rhs.length>0)
    {
        Node<T>* cur=rhs.rear;
        for (int i=0; i<rhs.length; i++)
        {
            cur=cur->next;
            add(cur->data);
        }   
    }
}

template <typename T>
ArrayList<T>::~ArrayList()
{
    Node<T>* cur=rear;
    if(length>0)
    {
        for(int i=1; i<=length; i++)
        {
            cur=rear->next;
            rear->next=cur->next;
            delete cur;
        }
        rear=nullptr;
        length=0;
    }
}

template <typename T>
void ArrayList<T>::add(T element)
{
    Node<T>* newNode=new Node<T>(element);
    if (length==0)
    {
        rear=newNode;
        newNode->next=rear;
    }
    else
    {
        newNode->next=rear->next;
        rear->next=newNode;
        rear=newNode;
    }
    length++;
}

template <typename T>
void ArrayList<T>::add(int index, T element)
{
    if(index < 0 || index > length)
    {
        throw ArrayListException("Index out of bounds");
    }
    Node<T>* newNode=new Node<T>(element);
    if(index==length) // empty list or adding to back of list
    {
        add(element);
    }
    else if(index==0) // adding to the front of the list
    {
        newNode->next=rear->next;
        rear->next=newNode;
        length++;
    }
    else // adding inbetween two nodes in the list
    {
        Node<T>* tmp;
        tmp=rear->next;
        while(index>1)
        {
            tmp=tmp->next;
            index--;
        }
        newNode->next=tmp->next;
        tmp->next=newNode;
        length++;
    }
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& other)
{
    if(this!=&other)
    {
        rear=nullptr;
        length=0;
        Node<T>* cur=other.rear;
        for (int i=0; i<other.length; i++)
        {
            cur=cur->next;
            add(cur->data);
        }
    }
    return* this;
}

template <typename T>
T& ArrayList<T>::operator[](int index)
{
    if(index < 0 || index >= length)
    {
        throw ArrayListException("Index out of bounds");
    }
    Node<T>* tmp=rear;
    for(int i=0;i<=index; i++)
    {
        tmp=tmp->next;
    }
    return tmp->data;
}

template <typename T>
T ArrayList<T>::remove(int index)
{
    if(index < 0 || index >= length)
    {
        throw ArrayListException("Index out of bounds");
    }
    T removeData;
    if(rear->next==rear) //only one item in list
    {
        removeData=rear->data;
        delete rear;
        rear=nullptr;
    }
    else
    {
        Node<T>* tmp;
        tmp=rear->next;
        if(index==length-1) //deleting last item on list
        {
            while(tmp->next!=rear)
            {
                tmp=tmp->next;
            }
            tmp->next=rear->next;
            removeData=rear->data;
            delete rear;
            rear=tmp;
        }
        else
        {
            Node<T>* bef=nullptr;
            for(int i=0; i<index; i++)
            {
                bef=tmp;
                tmp=tmp->next;
            }
            if(bef==nullptr)
            {
                rear->next=tmp->next;
            }
            else
            {
                bef->next=tmp->next;
            }
            removeData=tmp->data;
            delete tmp;
        }
    }
    length--;
return removeData;
}

template <typename T>
long ArrayList<T>::size() const
{
    return length;
}
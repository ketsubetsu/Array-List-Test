/**
 * An extensible circularly-linked array list header file
 * @author ketsubetsu
 * <pre>
 * File: ArrayList.h
 * </pre>
 */

#include <string>
#include <iostream>

#ifndef ARRAYLIST_H
#define ARRAYLIST_H

using namespace std;
//This file will: 
// 1. Define an exception class, ArrayListException
//
// 2. Define the public interface for the parameterized ArrayList class.
//    The ArrayList should have one external pointer to a node. I called 
//    mine rear but you may use other names that  are meaningful. Also, you want to keep 
//    track of the length of the ArrayList at all times. The ArrayList class must give a forward 
//    declaration of the Node class, which is inner class in the ArrayList class.
//3.  Define the Node class. This class will have a link to a Node (be self-referential) and will have only
//    none member function, a parameterized constructor.

class ArrayListException
{
private:
    string message;

public:
    ArrayListException(const string& aMessage)
    {
        message=aMessage;
    }
    string what() const
    {
        return message;
    }
};

template <typename T>
class ArrayList
{
private:
    template <typename U> class Node;
    Node<T>* rear;
    long length;

public:
    ArrayList();
    ArrayList(const ArrayList<T>& rhs);
    virtual ~ArrayList();
    void add(T element);
    void add(int index, T element);
    T& operator[](int index);
    ArrayList<T>& operator=(const ArrayList<T>& other);
    T remove(int index);
    long size() const;
};

template <typename U>
template <typename T>
class ArrayList<U>::Node
{
private:
    T data;
    Node<T>* next;
    friend class ArrayList<U>;

public:
    Node(T element);
};

#endif


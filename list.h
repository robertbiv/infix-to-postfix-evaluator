#ifndef __DLLIST__
#define __DLLIST__

#include <iostream>
#include <string>
using namespace std;

template<typename T> class List;

template<typename T>
class Node
{
private:
    T value;
    Node* prev;
    Node* next;
public:
    Node(T value, Node* prev = NULL, Node* next = NULL);
    friend class List<T>;
};

template<typename T>
class List
{
private:
    Node<T>* head;
    Node<T>* tail;
public:
    List();
    List(const List<T>& src);
    ~List();
    bool IsEmpty() const;
    T GetHead() const;
    T GetTail() const;
    void AddToHead(T v);
    void AddToTail(T v);
    T RemoveHead();
    T RemoveTail();

    operator string() const;
};

template<typename T>
Node<T>::Node(T value, Node* prev, Node* next)
{
    this->value = value;
    this->prev = prev;
    this->next = next;
}

template<typename T>
List<T>::operator string() const
{
    if (IsEmpty())
        return "()";
    stringstream os;
    os << "(";
    Node<T>* r = head;
    while (r != tail)
    {
        os << r->value << ",";
        r = r->next;
    }
    os << r->value << ")";
    string str = os.str();
    return str;
}

template<typename T>
List<T>::List()
{
// make list empty
    head = tail = NULL;
}

template<typename T>
List<T>::List(const List<T>& src)
{
// make list empty
    head = tail = NULL;

// copy all contents in src into this
    Node<T>* node = src.head;
    while(node != NULL)
    {
        AddToTail(node->value);
        node = node->next;
    }
}

template<typename T>
bool List<T>::IsEmpty() const
{
    return (head == NULL);
}

template<typename T>
List<T>::~List()
{
    while (!IsEmpty()) //deletes nodes until list is empty
        RemoveTail();
}

template<typename T>
T List<T>::GetHead() const
{
    if (!head)
        return -1;
    return head->value;
}

template<typename T>
T List<T>::GetTail() const
{
    if (!tail)
        return -1;
    return tail->value;
}

template<typename T>
void List<T>::AddToHead(T v)
{
    Node<T> *temp = new Node<T>(v, NULL, head);
    if (head)
        head->prev = temp;
    head = temp;
    if (!tail)
        tail = temp;
}

template<typename T>
void List<T>::AddToTail(T v)
{
    {
        Node<T> *temp = new Node<T>(v, tail, NULL);
        if (!head)
            head = temp;
        if(tail)
            tail->next = temp;
        tail = temp;
    }
}

template<typename T>
T List<T>::RemoveHead()
{
    T v = head->value;
    if (head == tail) {
        delete head;
        head = tail = NULL;
    }
    else {
        head = head->next;
        delete head->prev;
        head->prev = NULL;
    }
    return v; //returns the old head value
}

template<typename T>
T List<T>::RemoveTail()
{
    T d = tail->value;
    if (head == tail) {
        delete tail;
        head = tail = NULL;
    }
    else {
        tail = tail->prev;
        delete tail->next;
        tail->next = NULL;
    }
    return d; //returns the old tail value
}

#endif //__DLLIST__
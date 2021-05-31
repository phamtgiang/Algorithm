/* Created by Nguyen Duc Dung on 2019-09-03.
 * =========================================================================================
 * Name        : dsaLib.h
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - HCMUT
 * Description : The data structure library for Assignment 1
 * Course      : Data Structure and Algorithms - Fall 2019
 * =========================================================================================
 */

#ifndef DSA191_A1_DSALIB_H
#define DSA191_A1_DSALIB_H
#include <string>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

class DSAException {
    int     _error;
    string  _text;
public:

    DSAException() : _error(0), _text("Success") {}
    DSAException(int err) : _error(err), _text("Unknown Error") {}
    DSAException(int err, const char* text) : _error(err), _text(text) {}

    int getError() { return _error; }
    string& getErrorText() { return _text; }
};

template <class T>
struct L1Item {
    T data;
    L1Item<T> *pNext;
    L1Item() : pNext(NULL) {}
    L1Item(T &a) : data(a), pNext(NULL) {}
};

template <class T>
class L1List {
    L1Item<T>   *_pHead;// The head pointer of linked list
    L1Item<T>   *_pTail;
    size_t      _size;// number of elements in this list
public:
    L1List() : _pHead(NULL), _size(0) {}
    ~L1List()
    {
        while(!isEmpty())
           removeHead();
    }

    void    clean();
    bool    isEmpty() {
        return _pHead == NULL;
    }
    size_t  getSize() {
        return _size;
    }

    T&      at(int i)// give the reference to the element i-th in the list
    {
        L1Item<T>*pCur = this->_pHead;
        int j = 0 ;
	    while(j++ < i && pCur->pNext!= NULL)
		    pCur = pCur->pNext;
	    return pCur->data;
    }
    T&      operator[](int i)// give the reference to the element i-th in the list
    {
        L1Item<T> *current = _pHead;
        while(current != NULL && i-- > 0)
             current = current->pNext;
        return (current == NULL ? 0 : current->data);
        
    }

    bool    find(T& a, int& i)// find an element similar to a in the list. Set the found index to idx, set idx to -1 if failed. Return true if success.
    {
        i = -1;
		L1Item<T>*current = _pHead;
        while(current != NULL)
		{
			if(current->data == a)
            {
                i++;
                break;
            }
		    current = current->pNext;
			i++;
		}
        return i >= 0 ? true : false;
    }
    
    int     insert(int i, T& a)// insert an element into the list at location i. Return 0 if success, -1 otherwise
    {
        if(i < 0 || i > _size)return -1;
        if(isEmpty() || i == 0)
           insertHead(a);
        else if( i == _size)
           push_back(a);
        else{
            L1Item<T> *node = new L1Item<T>(a);
            L1Item<T> *p = _pHead;
            for(int j = 0 ; j < i - 1; j++)
               p = p->pNext;
            node->pNext = p->pNext;
            p->pNext = node;
            _size++;
        }
        return 0;
    }
    int     remove(int i)// remove an element at position i in the list. Return 0 if success, -1 otherwise.
    {
        
        if(i < 0 || i >= _size)return -1;
        if(i == 0)
           removeHead();
        else{
            L1Item<T>* p = _pHead;
            L1Item<T>* d = NULL;
            for(int j = 0; j < i - 1; j++)
                p = p->pNext;
            d = p->pNext;
            p->pNext = d->pNext;
            delete(d);
            _size--;
        }
        return 0;
    }
    int     push_back(T& a);// insert to the end of the list
    int     insertHead(T& a);// insert to the beginning of the list

    int     removeHead();// remove the beginning element of the list
    int     removeLast();// remove the last element of the list

    void    reverse();

    void    traverse(void (*op)(T&)) {
        // TODO: Your code goes here
    }
    void    traverse(void (*op)(T&, void*), void* pParam) {
        // TODO: Your code goes here
    }
    void _traverse(T* & array,int i)
	{
		L1Item<T> *p = _pHead;
		while(p != NULL )
		{
			array[i++] = p->data;
			p = p->pNext;
		}
	}
    bool update(int i, T& a){
        if(i < 0 || i >= _size)return false;
        L1Item<T>* p = _pHead;
        for(int j = 0; j < i; j++)
           p = p->pNext;
        p->data = a;
        return true;
    }
};

/// Insert item to the end of the list
/// Return 0 if success, -1 otherwise
template <class T>
int L1List<T>::push_back(T &a) {
    // TODO: Your code goes here
   if(isEmpty())
      insertHead(a);
   else{
       L1Item<T> *node = new L1Item<T>(a);
       _pTail->pNext = node;
       _pTail = _pTail->pNext;
       _size++;
   }
   return 0;
}

/// Insert item to the front of the list
/// Return 0 if success, -1 otherwise
template <class T>
int L1List<T>::insertHead(T &a) {
    // TODO: Your code goes here

    L1Item<T> *node = new L1Item<T>(a);
	if(isEmpty())
		_pTail = _pHead = node;
    else{
        node->pNext = _pHead;
        _pHead = node;
    }
    _size++;
    return 0;
}

/// Remove the first item of the list
/// Return 0 if success, -1 otherwise
template <class T>
int L1List<T>::removeHead() {
    // TODO: Your code goes here
    if(isEmpty())return -1;
    L1Item<T>* d = _pHead;
    _pHead = _pHead->pNext;
    delete(d);
    _size--;
    if(isEmpty())_pHead = _pTail = NULL;
    return 0;
}

/// Remove the last item of the list
/// Return 0 if success, -1 otherwise
template <class T>
int L1List<T>::removeLast() {
    // TODO: Your code goes here
    if(isEmpty())return -1;
    L1Item<T>* p = _pHead;
    if(_size == 1){
        delete(p);
        _pHead = _pTail = NULL;
    }
    else{
        while(p->pNext->pNext != NULL)
              p = p->pNext;
        L1Item<T>* d = _pTail;
        _pTail = p;
        delete(d);
    }  
    _size--;
    return 0;     
}

#endif //DSA191_A1_DSALIB_H

#include "stdafx.h"
#include <iostream>
using namespace std;
#include "stackm.h"

template <class T, int nEl>
void StackM <T, nEl> :: Push (T elem)
	{
		if(!Full())
		{
			data [nElements] = elem;
			nElements ++;
		}
		else 
			cout<<"Stack is full"<<endl;
	}

template <class T, int nEl>
T StackM <T, nEl> :: Pop ()
	{
		nElements --;
		return data [nElements];
	}

template <class T, int nEl>
int StackM <T, nEl> :: Number ()
	{
		return nElements;
	}

template <class T, int nEl>
int StackM <T, nEl> :: Empty ()
	{
		return (nElements == 0);
	}

template <class T, int nEl>
int StackM <T, nEl> :: Full ()
	{
		return (nElements == nEl);
	}

template <class T, int nEl>
const StackM<T>& StackM <T, nEl> :: operator=(const StackM<T>& p1)
	{

		nElements=p1.nElements;
		for(int i=0;i<nElements;i++)
			data[i]=p1.data[i];
		return *this;
	}
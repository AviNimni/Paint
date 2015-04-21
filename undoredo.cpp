#include "stdafx.h"
#include <iostream>
using namespace std;
#include "undoredo.h"

template <class T>
UndoRedo<T>::UndoRedo (const UndoRedo& UR1)
{
	Undo=UR1.Undo;
	Redo=UR1.Redo;
}

template <class T>
void UndoRedo<T>::AddNew (T elem)
{
	Undo.Push(elem);
}

template <class T>
void UndoRedo<T>::Delete ()
{
	Redo.Push(Undo.Pop());
}

template <class T>
T UndoRedo<T>::Top ()
{
	T Temp;
	Temp=Undo.Pop();
	Undo.Push(Temp);
	return Temp;
}

template <class T>
void UndoRedo<T>::PrintRedo ()
{
	StackM<T,50> Temp;
	T Print;
	while(!Redo.Empty())
	{
		Print=Redo.Pop();
		cout<<Print<<" ";
		Temp.Push(Print);
	}
	while(!Temp.Empty())
	{
		Redo.Push(Temp.Pop());
	}
}

template <class T>
void UndoRedo<T>::PrintAll ()
{
	StackM<T,50> Temp;
	T Print;
	cout<<"Undo : ";
	while(!Undo.Empty())
	{
		Print=Undo.Pop();
		cout<<Print<<" ";
		Temp.Push(Print);
	}
	cout<<"]";
	while(!Temp.Empty())
	{
		Undo.Push(Temp.Pop());
	}
	cout<<endl<<"Redo : ";
	while(!Redo.Empty())
	{
		Print=Redo.Pop();
		cout<<Print<<" ";
		Temp.Push(Print);
	}
	while(!Temp.Empty())
	{
		Redo.Push(Temp.Pop());
	}
	cout<<"]";
}


template <class T>
bool UndoRedo<T>::isEmpty () const
{
	return Redo.Empty();
}

template <class T>
void UndoRedo<T>::DeleteAll ()
{
	T Temp;
	while(!Redo.Empty())
	{
		Temp=Redo.Pop();
	}
	while(!Undo.Empty())
	{
		Temp=Undo.Pop();
	}
}

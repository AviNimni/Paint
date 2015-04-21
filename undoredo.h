#ifndef HEADER_H
#define HEADER_H

#include "stackm.h"

template <class T> class UndoRedo
{
public:
	StackM<T,50> Undo;
	StackM<T,50> Redo;
	UndoRedo(){}
	UndoRedo(const UndoRedo&);
	~UndoRedo(){}
	void AddNew(T elem);
	void Delete();
	T Top();
	void PrintRedo();
	void PrintAll();
	bool isEmpty() const;
	void DeleteAll();
};

#endif
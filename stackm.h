#ifndef STACKM_H
#define STACKM_H

template <class T, int nEl = 50> class StackM
{
	T	data [nEl];
	int	nElements;
public:
	StackM () :
		nElements (0)
		{ }
	void	Push (T elem);
	T	Pop ();
	int	Number ();
	int	Empty ();
	int	Full ();
	const StackM<T>& operator=(const StackM<T>&);
} ;

#endif
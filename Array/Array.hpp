
#include <assert.h>
template <class T>
class ArrayA
{
private:
	T* m_array;
	int _maxSize;
	int _numelements;
	int _growSize;

public:
	ArrayA(int size, int growby = 1) : m_array(NULL), _maxSize(0), _growSize(0), _numelements(0)
	{
		if (size)
		{
			_maxSize = size;
			m_array = new T[_maxSize];
			memset(m_array, 0, sizeof(T) * _maxSize);
			_growSize = ((growby > 0) ? growby : 0);
		}
	}

	~ArrayA()
	{
		if (m_array != NULL)
		{
			delete[] m_array;
			m_array = NULL;
		}
	}
	
	virtual void Push(T val)
	{
		assert(m_array != NULL);
		if (Search(val) == -1)
		{
			if (_numelements >= _maxSize)
			{
				Expand();
			}
			m_array[_numelements] = val;
			_numelements++;
		}
	}
	//virtual void Push(T val)
	//{
	//	assert(m_array != NULL);
	//	if(search(val) != 1)
	//	if (_numelements >= _maxSize)
	//	{
	//		Expand();
	//	}
	//	for (int i = 0; i < _numelements; i++)
	//	{
	//		if (m_array[i] > val)
	//			break;
	//		for (int K = _numelements; K > i; K--)
	//		{
	//			m_array[K] = m_array[K - 1];
	//		}
	//		m_array[i] = val
	//	}
	//	_numelements++;
	//}

	void Pop()
	{
		if (_numelements > 0)
			_numelements--;
	}

	void Remove(int index)
	{
		assert(m_array != NULL);
		if (index >= _maxSize)
			return;
		for (int i = index; i < _maxSize - 1; i++)
		{
			m_array[i] = m_array[i + 1];
		}
			_maxSize--;
		if (_numelements >= _maxSize)
			_numelements = _maxSize - 1;
	}

	virtual T& operator[] (int index)
	{
		return m_array[index];
	}

	bool Expand()
	{
		if (_growSize <= 0)
		{
			return false;
		}
		T* temp = new T[_maxSize + _growSize];
		memcpy(temp, m_array, sizeof(T) * _maxSize);
		delete[] m_array;
		m_array = temp;
		_maxSize += _growSize;
		return true;
	}

	virtual int Search(T searchkey)
	{

		if (!m_array)
			return -1;
		int lowerBound = 0;
		int upperBound = _numelements - 1;
		int current = 0;
		while (1)
		{
			current = (lowerBound + upperBound) >> 1;
			if (m_array[current] == searchkey)
			{
				return current;
			}
			else if (lowerBound > upperBound)
			{
				return -1;
			}
			else
			{
				if (m_array[current] < searchkey)
					lowerBound = current + 1;
				else upperBound = current - 1;
			}
		}
	}

	void Clear() {_numelements = 0;}

	int GetSize() {return _numelements;}

	int GetMaxSize() {return _maxSize;}

	int GetGrowSize() {return _growSize;}

	void SetGrowSize(int val) { _growSize = val; }
};
# Lesson 2
Arrays

## OddOccurrencesInArray
```cpp
int solution(std::vector<int> &A) 
{
    // write your code in C++14 (g++ 6.2.0)
    
	int nRes = 0;
	for( int nData : A )
		nRes ^= nData;

	return nRes;
}
```

## CyclicRotation
```cpp
std::vector<int> solution(std::vector<int> &A, int K)
{
	if( A.empty() )
		return std::vector<int>();

	auto size = A.size();
	auto res = K % size;

	std::vector<int> vRes( size );
	for( unsigned int indx=0; indx<size; ++indx )
	{
		auto i = (indx + res) % size;
		vRes[ i ] = A[ indx ];
	}

	return vRes;
}
```



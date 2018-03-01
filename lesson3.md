Lesson 3
# Time Complexity

## TapeEquilibrium
```cpp
#include <limits>
int solution(std::vector<int> &A)
{
    // write your code in C++14 (g++ 6.2.0)
    
    int nAcc = 0;
    for( auto nData : A ) 
        nAcc += nData;

    int nLeft = 0;
    int nRight = nAcc;
    int nMin = std::numeric_limits<int>::max();
    int nSize = A.size();
    for( int indx=0; indx<nSize-1; ++indx )
    {
        nLeft += A[indx];
        nRight -= A[indx];
        nMin = std::min( nMin, abs(nLeft - nRight) );
    }
    
    return nMin;
}
```

## FrogJmp
```cpp
int solution(int X, int Y, int D) 
{
    // write your code in C++14 (g++ 6.2.0)
    
    int nData = (Y - X) / D;
    int nRes = (Y - X ) % D;
    return nRes > 0 ? (nData+1) : nData;

}
```

## PermMissingElem
```cpp
#include <algorithm>
int solution(std::vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
	if( A.empty() ) return 1;

	int nRes = 0;
	if( A.size() > 1 )
	{
		std::sort( A.begin(), A.end() );
		for( int nData=A.front(); nData<=A.back(); ++nData )
			nRes ^= nData;

		for( int nData : A )
			nRes ^= nData;
	}

	if( nRes == 0 )
		return A.front() > 1 ? 1 : A.back()+1;

	return nRes;
}
```



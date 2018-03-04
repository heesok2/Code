Lesson 4
# Counting Elements

## PermCheck
```cpp
#include <algorithm>
int solution(std::vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
	const int RES_TRUE = 1;
	const int RES_FALSE = 0;

	std::sort( A.begin(), A.end() );

	int nSize = A.size();
	for( int indx=0; indx<nSize; ++indx )
	{
		if( A[indx] != (indx+1) ) 
			return RES_FALSE;
	}

	return RES_TRUE;
}
```

## FrogRiverOne
```cpp
#include <limits>
int solution2(int X, std::vector<int> &A)
{   
	std::vector<int> vFinish( X, -1 );

	int nSize = A.size();
	for( int indx=0; indx<nSize; ++indx )
	{
		if( A[indx] > X ) continue;

		if( vFinish[ A[indx]-1 ] == -1 ) vFinish[ A[indx]-1 ] = indx;
		else 
		{
			vFinish[ A[indx]-1 ] = std::min( vFinish[ A[indx]-1 ], indx );
		}
	}

	int nMax = 0;
	for( int nData : vFinish )
	{
		if( nData == -1 ) return -1;
		nMax = std::max( nMax, nData );
	}

	return nMax;
}
```

## MissingInteger
```cpp
#include <algorithm>
int solution(std::vector<int> &A)
{
	std::sort( A.begin(), A.end() );

	int nLast = A.back();
	if( nLast < 1 ) return 1;

	std::vector<bool> vFlag( nLast, false );

	for( int indx : A )
	{
		if( indx > 0 ) vFlag[indx] = true;
	}

	for( int indx=1; indx<=nLast; ++indx )
	{
		if( !vFlag[indx] )
			return indx;
	}

	return nLast+1;
}
```

## MaxCounters
```cpp
std::vector<int> solution(int N, std::vector<int> &A)
{
	std::vector<int> vRes( N, 0 );

	int nMax = 0;
	int nLimit = 0;
	for( int nData : A )
	{
		if( nData >= 1 && nData <= N )
		{
			vRes[ nData-1 ] = std::max( vRes[ nData-1 ], nLimit );
			vRes[ nData-1 ]++;
			nMax = std::max( nMax, vRes[ nData-1 ] );
		}
		else if( nData == N+1 )
		{
			// std::fill( vRes.begin(), vRes.end(), nMax );
			
			nLimit = nMax;
		}
	}

	for( int indx=0; indx<N; ++indx )
		vRes[ indx ] = std::max( vRes[ indx ], nLimit );

	return vRes;
}
```
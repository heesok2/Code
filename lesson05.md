Lesson 5
# Prefix Sums

## CountDiv
```cpp
int solution(int A, int B, int K)
{
	int nRes = A % K;
	int nData = A;
	
	if( nRes != 0 )
		nData = A - nRes + K;

	if( B < nData ) 
		return 0;

	return ( ((B - nData) / K) + 1 );
}
```

## PassingCars
```cpp
int solution(vector<int> &A)
{
	unsigned int nCount = 0;
	unsigned int nTotal = 0;

	int nSize = (int)A.size();
	for( int nIndx=nSize-1; nIndx>=0; --nIndx )
	{
		if( A[ nIndx ] == 0 )
			nTotal += nCount;
		else
			nCount++;
	}

	return nTotal <= 1000000000 ? nTotal : -1;
}
```

## MinAvgTwoSlice
```cpp

```

## GenomicRangeQuery
```cpp

```

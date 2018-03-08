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
        {
            nTotal += nCount;
            if( nTotal > 1000000000 )
                return -1;
        }
        else
            nCount++;
    }

    return nTotal;
}
```

## GenomicRangeQuery
```cpp
vector<int> solution(string &S, vector<int> &P, vector<int> &Q)
{
    int nLength = S.length();
    std::vector<int> vA( nLength, 0 );
    std::vector<int> vC( nLength, 0 );
    std::vector<int> vG( nLength, 0 );
    for( int indx=0; indx<nLength; ++indx )
    {
        if( indx > 0 )
        {
            vA[indx] = vA[indx-1];
            vC[indx] = vC[indx-1];
            vG[indx] = vG[indx-1];
        }

        switch( S[indx] )
        {
        case 'A': vA[indx]++; break;
        case 'C': vC[indx]++; break;
        case 'G': vG[indx]++; break;
        }
    }

    int nSize = P.size();
    std::vector<int> vResult( nSize, 0 );
    for( int indx=0; indx<nSize; ++indx )
    {
        int nValue = 0;
        if( P[indx] == Q[indx] )
        {
            switch( S[ P[indx] ] )
            {
            case 'A': nValue = 1; break;
            case 'C': nValue = 2; break;
            case 'G': nValue = 3; break;
            case 'T': nValue = 4; break;
            }
        }
        else
        {
            if( P[indx] == 0 )
            {
                if( vA[ Q[indx] ] )
                    nValue = 1;
                else if( vC[ Q[indx] ] )
                    nValue = 2;
                else if( vG[ Q[indx] ] )
                    nValue = 3;
                else 
                    nValue = 4;
            }
            else
            {
                if( vA[ P[indx]-1 ] < vA[ Q[indx] ] )
                    nValue = 1;
                else if( vC[ P[indx]-1 ] < vC[ Q[indx] ] )
                    nValue = 2;
                else if( vG[ P[indx]-1 ] < vG[ Q[indx] ] )
                    nValue = 3;
                else
                    nValue = 4;
            }
        }

        vResult[indx] = nValue;
    }

    return vResult;
}
```

## MinAvgTwoSlice
```cpp
#include <algorithm>
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
        int nDataSize = A.size();
    std::vector<int> vData( nDataSize, 0 );
    for( int indx=1; indx<nDataSize; ++indx )
    {
        vData[indx] = vData[indx-1];
        vData[indx] += A[indx-1];
    }

    int nRes = 0;
    double dMin = std::numeric_limits<double>::max();
    for( int indx=1; indx<nDataSize; ++indx )
    {
        double dEnd = (double)(vData[indx] + A[indx]);
        double dBeg = (double)(vData[indx-1]);
        double dValue = (dEnd - dBeg) / 2.0;
        if( dMin > dValue ) 
        {
            dMin = dValue;
            nRes = indx-1;
        }
    }

    for( int indx=2; indx<nDataSize; ++indx ) 
    {
        double dEnd = (double)(vData[indx] + A[indx]);
        double dBeg = (double)(vData[indx-2]);
        double dValue = (dEnd - dBeg) / 3.0;
        if( dMin > dValue ) 
        {
            dMin = dValue;
            nRes = indx-2;
        }
    }

    return nRes;
}
```

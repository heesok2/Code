Lesson 6
# Sorting

## Triangle
```cpp
#include <algorithm>
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)

    int nSize = A.size();
    if( nSize < 3 ) return 0;

    std::sort( A.begin(), A.end() );

    for( int indx=0; indx<(nSize-2); ++indx )
    {
        long lMin = A[indx  ];
        long lMid = A[indx+1];
        long lMax = A[indx+2];
        if( lMin >= (lMid+lMax) ) continue;
        if( lMid >= (lMax+lMin) ) continue;
        if( lMax >= (lMin+lMid) ) continue;

        return 1;
    }

    return 0;
}
```

## Distinct
```cpp
#include <algorithm>
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)

    std::sort( A.begin(), A.end() );
    auto itr = std::unique( A.begin(), A.end() );

    if( itr != A.end() ) 
    {
        A.erase( itr, A.end() );
    }

    return A.size();
}
```

## MaxProductOfThree
```cpp

```

## NumberOfDiscIntersections
```cpp

```
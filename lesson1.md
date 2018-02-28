# Lesson 1

BinaryGap
======

```cpp

int solution(int N) 
{
    // write your code in C++14 (g++ 6.2.0)
    
        const int N_FLG = 0x1;
        const int N_EOF = 0x0;
        
        int nMax = 0;
        int nAcc = 0;
        int nData = 0;
        while( N != N_EOF )
        {
            if( N & N_FLG )
            {
                nMax = std::max( nMax, nAcc );
                nAcc = 0;
                nData = N & N_FLG;
            }
            else
            {
                nAcc += nData;
            }
            
            N = N >> 1;
        }
        
        return nMax;
}


```


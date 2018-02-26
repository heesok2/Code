#include <iostream>

int solution(int N)
{ 
	const int uiFlag = 0x1;
	
	int nMax = 0;
	int nCount = -1;
	int nAccum = 0;
	while( N ) 
	{
		if( uiFlag & N )
		{
			nMax = std::max( nMax, nCount );
			nCount = 0;
			nAccum = uiFlag & N;
		}
		else
		{
			nCount += nAccum;
		}

		N = N >> 1;
	}

	return nMax;
}

void main(void)
{
	int n = 9;
	solution(n);
}

/*
양의 정수 N 내의 이진 갭은 N의 이진 표현에서 양 끝의 것들로 둘러싸인 연속적인 0의 임의의 최대 시퀀스이다.

예를 들어 숫자 9는 2 진 표현 1001을 가지며 2 길이의 2 진 갭을 포함합니다. 숫자 529는 2 진 표현 1000010001을 가지며 2 개의 2 진 갭 (길이 4와 길이 3 중 하나)을 포함합니다. 숫자 20은 2 진 표현 10100을 가지며 다음을 포함합니다. 하나의 이진 갭은 길이 1이다. 숫자 15는 2 진 표현 (1111)을 가지며 2 진 갭을 갖지 않는다.

함수를 작성하십시오.

int 솔루션 (int N);

양의 정수 N이 주어지면 가장 긴 바이너리 갭의 길이를 반환합니다. N에 바이너리 갭이 포함되어 있지 않으면 함수는 0을 반환해야합니다.

예를 들어, N = 1041이 주어지면 함수는 5를 반환해야합니다. N은 이진 표현 10000010001을 가지므로 가장 긴 이진 간격은 길이 5입니다.

가정하자면 :

N은 [1..2,147,483,647] 범위의 정수입니다.
복잡성:

기대 최악의 경우의 시간 복잡도는 O (log (N))이다.
예상 최악의 공간 복잡도는 O (1)입니다.
Codility Limited의 저작권 2009-2018. 판권 소유. 무단 복사, 출판 또는 공개가 금지되어 있습니다.
*/


/*
A binary gap within a positive integer N is any maximal sequence of consecutive zeros that is surrounded by ones at both ends in the binary representation of N.

For example, number 9 has binary representation 1001 and contains a binary gap of length 2. The number 529 has binary representation 1000010001 and contains two binary gaps: one of length 4 and one of length 3. The number 20 has binary representation 10100 and contains one binary gap of length 1. The number 15 has binary representation 1111 and has no binary gaps.

Write a function:

int solution(int N);

that, given a positive integer N, returns the length of its longest binary gap. The function should return 0 if N doesn't contain a binary gap.

For example, given N = 1041 the function should return 5, because N has binary representation 10000010001 and so its longest binary gap is of length 5.

Assume that:

N is an integer within the range [1..2,147,483,647].
Complexity:

expected worst-case time complexity is O(log(N));
expected worst-case space complexity is O(1).
Copyright 2009–2018 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/

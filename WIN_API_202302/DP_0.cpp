#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

// DP : Dynamic Programming (동적 계획법)
// 컴퓨터 공학의  Dynamic과는 아무런 관련이 없다(??)
// 사용한 이유 => 멋있어서
// ==> 수학에서 최적화 기법으로 나온 알고리즘 디자인 패러다임.

// 케싱 :  참조 무결성이 지켜져야한다. 외부의 전역변수를 가져와 그것으로 절대 값이 바뀌면 안된다.
/int chache[100];

// 부분문제 : 
//f(n-1) + f(n-2);

// 참조 무결성 : 

// 피보나치 수열
// f(0) =1
// f(1) =1
// f(n) =f(n-1) + f(n-2)
// f(2) =2
// f(3) =3

// 과제 nCr 구현 과제.

int NCR(int n, int r, int& count)
{
	if (n == 0 || n == 1)
		return 1;

	if (n == 3)
		++count;
	// 메모이제이션, 캐싱
	if (chache[n] != -1)
		return chache[n];

	 return chchae[n] = n!/r*(n-r);
}


int Fibonacci(int n, int& count)
{
	// 기저사항
	if(n ==0 || n ==1)
	return 1;

	if (n == 3)
		++count;
	// 메모이제이션, 캐싱
	if(chache[n] != -1)
	return chache[n];

	// 구하기
	return chache[n] = Fibonacci(n-1, count) + Fibonacci(n-2 , count);
}

int main()
{
	int count =0;

	for (int i = 1; i < 100; i++)
	{
		chache[i] = -1;
	}

	_int64 start = GetTickCount64();
	cout << Fibonacci(40, count) << endl;
	cout << count <<"번" << endl;

	_int64 end = GetTickCount64();

	cout << end - start << "ms" << endl;

	return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

// DP : Dynamic Programming (���� ��ȹ��)
// ��ǻ�� ������  Dynamic���� �ƹ��� ������ ����(??)
// ����� ���� => ���־
// ==> ���п��� ����ȭ ������� ���� �˰��� ������ �з�����.

// �ɽ� :  ���� ���Ἲ�� ���������Ѵ�. �ܺ��� ���������� ������ �װ����� ���� ���� �ٲ�� �ȵȴ�.
/int chache[100];

// �κй��� : 
//f(n-1) + f(n-2);

// ���� ���Ἲ : 

// �Ǻ���ġ ����
// f(0) =1
// f(1) =1
// f(n) =f(n-1) + f(n-2)
// f(2) =2
// f(3) =3

// ���� nCr ���� ����.

int NCR(int n, int r, int& count)
{
	if (n == 0 || n == 1)
		return 1;

	if (n == 3)
		++count;
	// �޸������̼�, ĳ��
	if (chache[n] != -1)
		return chache[n];

	 return chchae[n] = n!/r*(n-r);
}


int Fibonacci(int n, int& count)
{
	// ��������
	if(n ==0 || n ==1)
	return 1;

	if (n == 3)
		++count;
	// �޸������̼�, ĳ��
	if(chache[n] != -1)
	return chache[n];

	// ���ϱ�
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
	cout << count <<"��" << endl;

	_int64 end = GetTickCount64();

	cout << end - start << "ms" << endl;

	return 0;
}
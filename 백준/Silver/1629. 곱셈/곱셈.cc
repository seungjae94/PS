#include <iostream>

int pow(int A, int n, int C)
{
	if (n == 0)
	{
		return 1 % C;
	}

	if (n == 1)
	{
		return A % C;
	}

	__int64_t Value = pow(A, n / 2, C);
	Value = (Value * Value) % C;
	return (Value * pow(A, n % 2, C)) % C;
}

int main()
{
	int A = 0;
	int B = 0;
	int C = 0;
	std::cin >> A;
	std::cin >> B;
	std::cin >> C;

	std::cout << pow(A, B, C);
}
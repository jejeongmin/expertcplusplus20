#pragma once

#include <iostream>

using namespace std;

// �̰� �����ϰ� �� �� �ִ� ��ʴ� �� �𸣰ڴٸ�
// �Լ� ���� Ÿ�� ���� �Ʒ��� ���� ������� auto �� ����ϸ� �����Ϸ��� �˾Ƽ� �߷��Ѵ�.
auto addNumbers(int number1, int number2)
{
	std::cout << "enter function " << __func__ << std::endl;
	return number1 + number2;
}

int main()
{
	int	numbers[]{ 3, 5 };
	printf("%d+%d=%d", numbers[0], numbers[1], addNumbers(numbers[0], numbers[1]));

	// ������ ���ε�

	return 0;
}

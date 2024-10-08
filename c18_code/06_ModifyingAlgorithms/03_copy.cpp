#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

// int 타입 컨테이너에 원소를 채우는 함수 템플릿
// 이때 컨테이너는 반드시 push_back()을 제공해야 한다.
template<typename Container>
void populateContainer(Container& cont)
{
	int num;

	while (true) {
		cout << "Enter a number (0 to quit): ";
		cin >> num;
		if (num == 0) {
			break;
		}
		cont.push_back(num);
	}
}

/*
	copy 건, copy_backward 건 copy source 와 copy target 이 겹치면 안된다.
	특수한 조건에는 겹치는 걸 허락하는 경우가 있다고 하지만,
	그런 특수한 경우는 기억도 하지 말고 쓰지 말자.
*/
int main()
{
	vector<int> vec1, vec2;

	populateContainer(vec1);

	vec2.resize(size(vec1));

	copy(cbegin(vec1), cend(vec1), begin(vec2));

	for (const auto& i : vec2) { cout << i << " "; }

	return 0;
}

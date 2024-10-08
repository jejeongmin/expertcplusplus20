#include <algorithm>
#include <functional>
#include <iterator>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

// int 컨테이너를 채우는 함수 템플릿
// 컨테이너는 반드시 push_back()을 제공해야 한다.
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

int main()
{
	vector<int> vectorOne;
	set<int> setOne;
	populateContainer(vectorOne);

	insert_iterator<set<int>> inserter(setOne, begin(setOne));
	copy_if(cbegin(vectorOne), cend(vectorOne), inserter,
		[](int i) { return i != 100; });

	// inserter() 함수를 이용한 구현
	//copy_if(cbegin(vectorOne), cend(vectorOne),
	//	inserter(setOne, begin(setOne)),
	//	[](int i) { return i != 100; });

	// C++17의 생성자에 대한 템플릿 인수 추론 기능을 적용한 코드
	//copy_if(cbegin(vectorOne), cend(vectorOne),
	//	insert_iterator(setOne, begin(setOne)),
	//	[](int i) { return i != 100; });

	copy(cbegin(setOne), cend(setOne), ostream_iterator<int>(cout, " "));
	cout << endl;

	return 0;
}

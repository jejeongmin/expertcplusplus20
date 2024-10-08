#include <iostream>
#include <vector>
#include <utility>

#define MAIN_7
#ifdef MAIN_7


using namespace std;

void printVec(const vector<int>& arr)
{
	for (int i : arr) {
		cout << i << " ";
	}
	cout << endl;
} 

pair<vector<int>, vector<int>> separateOddsAndEvens(const vector<int>& arr)
{
	vector<int> odds, evens;
	for (int i : arr) {
		if (i % 2 == 1) {
			odds.push_back(i);
		} else {
			evens.push_back(i);
		}
	}
	return make_pair(odds, evens);
}

int main()
{
	vector<int> vecUnSplit = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	auto[odds, evens] = separateOddsAndEvens(vecUnSplit);	// 리턴값에 구조적 바인딩 활용(c++17 이후 지원)
	printVec(odds);
	printVec(evens);

	return 0;
}

#endif
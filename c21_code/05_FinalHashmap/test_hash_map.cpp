#include "hash_map.h"
#include <iostream>
#include <map>

using namespace ProCpp;
using namespace std;

int main()
{
	hash_map<string, int> myHash_temp;
	myHash_temp.insert(make_pair("KeyOne", 100));
	myHash_temp.insert(make_pair("KeyTwo", 200));
	myHash_temp.insert(make_pair("KeyThree", 300));

	hash_map<string, int> myHash{
			{ "KeyOne", 100 },
			{ "KeyTwo", 200 } };

	myHash.insert({
			{ "KeyThree", 300 },
			{ "KeyFour", 400 } });

	for (auto it = myHash.cbegin(); it != myHash.cend(); ++it) {
		// ->와 *를 둘 다 사용해서 이 연산을 테스트한다.
		cout << it->first << " maps to " << (*it).second << endl;
	}

	cout << "----" << endl;

	// 범위 기반 for문으로 원소를 출력한다.
	for (auto& p : myHash) {
		cout << p.first << " maps to " << p.second << endl;
	}

	cout << "----" << endl;

	// 범위 기반 for문과 C++17 구조적 바인딩을 사용해서 원소를 출력한다.
	for (auto&[key, value] : myHash) {
		cout << key << " maps to " << value << endl;
	}

	cout << "----" << endl;

	// 해시맵의 원소를 모두 담은 std::map을 생성한다.
	map<string, int> myMap(cbegin(myHash), cend(myHash));
	for (auto& p : myMap) {
		cout << p.first << " maps to " << p.second << endl;
	}

	cout << "----" << endl;

	auto found = myHash.find("KeyThree");
	if (found != end(myHash))
	{
		cout << "Found KeyThree: value = " << found->second << endl;
	}

	map<string, int> someMap{ {"One", 1},{"Two", 2} };
	hash_map<string, int> hashMapFromMap(cbegin(someMap), cend(someMap));

	hash_map<string, int> myHash2;
	myHash.swap(myHash2);

	hash_map<string, int> myHash3(std::move(myHash2));

	cout << myHash3.size() << endl;
	cout << myHash3.max_size() << endl;

	// 동등 비교자 검사
	{
		hash_map<string, int> myHash1{
			{ "KeyOne", 100 },
			{ "KeyTwo", 200 } };

		hash_map<string, int> myHash2{
			{ "KeyOne", 100 },
			{ "KeyTwo", 200 } };

		hash_map<string, int> myHash3{
			{ "KeyOne", 100 },
			{ "KeyThree", 300 } };

		if (myHash1 == myHash2)
			cout << "myHash1 and myHash2 is equal." << endl;
		else
			cout << "myHash1 and myHash2 is not equal." << endl;

		if (myHash1 != myHash3)
			cout << "myHash1 and myHash3 is not equal." << endl;
		else
			cout << "myHash1 and myHash3 is equal." << endl;
	}

	// reverse iterator 테스트
	{
		hash_map<int, int> myHash{
			{ 1, 100 },
			{ 2, 200 },
			{ 3, 300 }, 
			{ 4, 400 }, };

		for (auto it = myHash.cbegin(); it != myHash.cend(); ++it) {
			// ->와 *를 둘 다 사용해서 이 연산을 테스트한다.
			cout << it->first << " maps to " << (*it).second << endl;
		}

		//const_hash_map_reverse_iterator<hash_map<int, int>>	iterator(1, std::rbegin(myHash.mBuckets), &myHash);
		//auto it = myHash.rbegin();
		for (auto it = myHash.crbegin(); it != myHash.crend(); ++it) {
			// ->와 *를 둘 다 사용해서 이 연산을 테스트한다.
			cout << it->first << " maps to " << (*it).second << endl;
		}
	}
	
	return 0;
}

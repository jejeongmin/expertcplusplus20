#include <fstream>
#include <iostream>
#include <stdexcept>

using namespace std;

void funcOne();
void funcTwo();

int main()
{
	try {
		funcOne();
	} catch (const exception& /* e */) {
		cerr << "Exception caught!" << endl;
		return 1;
	}

	return 0;
}

void funcOne()
{
	string str1;
	string* str2 = new string();
	funcTwo();
	delete str2;			// 여기는 메모리가 유실된다.
}

void funcTwo()
{
	ifstream fileStream;
	fileStream.open("filename");
	throw exception();
	fileStream.close();		// 여기는 로컬 변수인 fileStream 의 소멸자가 호출되면서 close 는 처리된다.
}

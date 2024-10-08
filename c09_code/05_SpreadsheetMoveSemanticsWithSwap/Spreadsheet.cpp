#include "Spreadsheet.h"
#include <stdexcept>
#include <utility>
#include <iostream>

using namespace std;

Spreadsheet::Spreadsheet(size_t width, size_t height)
	: mWidth(width)
	, mHeight(height)
{
	cout << "Normal constructor" << endl;

	mCells = new SpreadsheetCell*[mWidth];
	for (size_t i = 0; i < mWidth; i++) {
		mCells[i] = new SpreadsheetCell[mHeight];
	}
}

Spreadsheet::~Spreadsheet()
{
	for (size_t i = 0; i < mWidth; i++) {
		delete[] mCells[i];
	}
	delete[] mCells;
	mCells = nullptr;
}

Spreadsheet::Spreadsheet(const Spreadsheet& src)
	: Spreadsheet(src.mWidth, src.mHeight)
{
	cout << "Copy constructor" << endl;

	// 이 생성자의 ctor-이니셜라이저는 먼저 적절한 양의 메모리를 할당하는 작업을
	// 비복제 버전의 생성자에게 위임한다.

	// 그러고 나서 실제로 값을 복제하는 작업을 수행한다.
	for (size_t i = 0; i < mWidth; i++) {
		for (size_t j = 0; j < mHeight; j++) {
			mCells[i][j] = src.mCells[i][j];
		}
	}
}

void Spreadsheet::verifyCoordinate(size_t x, size_t y) const
{
	if (x >= mWidth || y >= mHeight) {
		throw std::out_of_range("");
	}
}

void Spreadsheet::setCellAt(size_t x, size_t y, const SpreadsheetCell& cell)
{
	verifyCoordinate(x, y);
	mCells[x][y] = cell;
}

SpreadsheetCell& Spreadsheet::getCellAt(size_t x, size_t y)
{
	verifyCoordinate(x, y);
	return mCells[x][y];
}

void swap(Spreadsheet& first, Spreadsheet& second) noexcept
{
	using std::swap;

	swap(first.mWidth, second.mWidth);
	swap(first.mHeight, second.mHeight);
	swap(first.mCells, second.mCells);
}

/*
	std::swap 은 이동의미론을 활용하여 아래와 같이 구현되어 있다.

	void swap(T& a, T& b)
	{
		T	temp(std::move(a));
		a = std::move(b);
		b = std::move(temp);
	}
*/

Spreadsheet& Spreadsheet::operator=(const Spreadsheet& rhs)
{
	cout << "Copy assignment operator" << endl;

	// 자신을 대입하는지 확인한다.
	if (this == &rhs) {
		return *this;
	}

	// 복제 후 맞바꾸기(copy-and-swap) 패턴 적용
	Spreadsheet temp(rhs); // 모든 작업을 임시 인스턴스에서 처리한다.
	swap(*this, temp); // 예외를 발생하지 않는 연산으로만 처리한다.
	return *this;
}

// 이동 생성자
Spreadsheet::Spreadsheet(Spreadsheet&& src) noexcept
	: Spreadsheet()		// -> 기본 생성자를 default 로 선언해 사용
{
	cout << "Move constructor" << endl;

	swap(*this, src);
}

// 이동 대입 연산자
Spreadsheet& Spreadsheet::operator=(Spreadsheet&& rhs) noexcept
{
	cout << "Move assignment operator" << endl;

	Spreadsheet temp(std::move(rhs));	// r-value 를 move 를 통해 전달해서 앞서의 코드 ( 04_SpreadsheetMoveSemantics ) 보다 좀더 간단히 구현
	swap(*this, temp);
	return *this;
}

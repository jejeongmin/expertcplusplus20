#include "CfhdClient.h"
#include <stdexcept>
#include <utility>

CfhdClient::CfhdClient(size_t width, size_t height)
	: mWidth(width)
	, mHeight(height)
{
	mCells = new SpreadsheetCell*[mWidth];
	for (size_t i = 0; i < mWidth; i++) {
		mCells[i] = new SpreadsheetCell[mHeight];
	}
}

CfhdClient::~CfhdClient()
{
	for (size_t i = 0; i < mWidth; i++) {
		delete[] mCells[i];
	}
	delete[] mCells;
	mCells = nullptr;
}

CfhdClient::CfhdClient(const CfhdClient& src)
	: Spreadsheet(src.mWidth, src.mHeight)
{
	// �� �������� ctor-�̴ϼȶ������� ���� ������ ���� �޸𸮸� �Ҵ��ϴ� �۾���
	// ���� ������ �����ڿ��� �����Ѵ�.

	// �׷��� ���� ������ ���� �����ϴ� �۾��� �����Ѵ�.
	for (size_t i = 0; i < mWidth; i++) {
		for (size_t j = 0; j < mHeight; j++) {
			mCells[i][j] = src.mCells[i][j];
		}
	}
}

void CfhdClient::verifyCoordinate(size_t x, size_t y) const
{
	if (x >= mWidth || y >= mHeight) {
		throw std::out_of_range("");
	}
}

void CfhdClient::setCellAt(size_t x, size_t y, const int cell)
{
	verifyCoordinate(x, y);
	mCells[x][y] = cell;
}

int CfhdClient::getCellAt(size_t x, size_t y)
{
	verifyCoordinate(x, y);
	return mCells[x][y];
}

void swap(CfhdClient& first, CfhdClient& second) noexcept
{
	using std::swap;

	swap(first.mWidth, second.mWidth);
	swap(first.mHeight, second.mHeight);
	swap(first.mCells, second.mCells);
}

CfhdClient& CfhdClient::operator=(const Spreadsheet& rhs)
{
	// �ڽ��� �����ϴ��� Ȯ���Ѵ�.
	if (this == &rhs) {
		return *this;
	}

	// ���� �� �¹ٲٱ�(copy-and-swap) ���� ����
	CfhdClient temp(rhs); // ��� �۾��� �ӽ� �ν��Ͻ����� ó���Ѵ�.
	swap(*this, temp); // ���ܸ� �߻����� �ʴ� �������θ� ó���Ѵ�.
	return *this;
}

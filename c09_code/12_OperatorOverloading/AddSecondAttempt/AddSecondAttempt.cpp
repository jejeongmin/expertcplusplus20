#include "AddSecondAttempt.h"

using namespace std;

namespace AddSecondAttempt
{
	SpreadsheetCell::SpreadsheetCell(double initialValue)
		: mValue(initialValue)
	{
	}

	SpreadsheetCell::SpreadsheetCell(string_view initialValue)
		: mValue(stringToDouble(initialValue))
	{
	}

	void SpreadsheetCell::set(double inValue)
	{
		mValue = inValue;
	}

	void SpreadsheetCell::set(string_view inString)
	{
		mValue = stringToDouble(inString);
	}

	string SpreadsheetCell::doubleToString(double inValue)
	{
		return to_string(inValue);
	}

	double SpreadsheetCell::stringToDouble(string_view inString)
	{
		return strtod(inString.data(), nullptr);
	}

	SpreadsheetCell SpreadsheetCell::operator+(const SpreadsheetCell& cell) const
	{
		return SpreadsheetCell(getValue() + cell.getValue());
	}

	/*
	SpreadsheetCell SpreadsheetCell::operator+(double rhs) const
	{
		return SpreadsheetCell(getValue() + rhs);
	}
	*/
}
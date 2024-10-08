#pragma once

#include <cstddef>
#include <string>
#include <string_view>

namespace AddFirstAttempt
{
	class SpreadsheetCell
	{
	public:
		SpreadsheetCell() = default;
		SpreadsheetCell(double initialValue);
		SpreadsheetCell(std::string_view initialValue);

		void set(double inValue);
		void set(std::string_view inString);

		double getValue() const { mNumAccesses++; return mValue; }
		std::string getString() const { mNumAccesses++; return doubleToString(mValue); }

		static std::string doubleToString(double inValue);
		static double stringToDouble(std::string_view inString);

		SpreadsheetCell add(const SpreadsheetCell& cell) const;

	private:
		double mValue = 0;
		mutable size_t mNumAccesses = 0;
	};
}
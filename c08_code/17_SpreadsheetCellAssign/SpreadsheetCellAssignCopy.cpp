#include "SpreadsheetCell.h"
#include <string>

using namespace std;

//#define MAIN_1

#ifdef MAIN_1
int main()
{
  SpreadsheetCell myCell(5);
  SpreadsheetCell anotherCell(myCell);
  SpreadsheetCell aThirdCell = myCell;		// 대입 연산 처럼 보이지만, 생성자 초기화를 한다. 바로 위의 코드와 동일
  anotherCell = myCell; // anotherCell에 대해 operator=를 호출한다.

  SpreadsheetCell myCell2(5);
  string s1;
  s1 = myCell2.getString();

  SpreadsheetCell myCell3(5);
  string s2 = myCell3.getString();

  return 0;
}
#endif
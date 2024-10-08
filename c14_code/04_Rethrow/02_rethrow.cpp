#include <iostream>
#include <stdexcept>

using namespace std;

void g() { throw invalid_argument("Some exception"); }

void f()
{
    try {
        g();
    } catch (const exception& e) {
        cout << "caught in f: " << e.what() << endl;
        throw;  // 다시 던진다. 이때 throw e 와 같이 하면 안된다. 예외 객체가 다형성에 의해 다른 타입으로 바뀔 수 있다.
    }
}

int main()
{
    try {
        f();
    } catch (const invalid_argument& e) {
        cout << "invalid_argument caught in main: " << e.what() << endl;
    } catch (const exception& e) {
        cout << "exception caught in main: " << e.what() << endl;
    }
    return 0;
}

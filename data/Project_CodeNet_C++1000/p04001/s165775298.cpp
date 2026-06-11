#include <iostream>
#include <string>
using namespace std;
using Int = long long int;
using UInt = unsigned long long int;

Int PerseAndCalc(string& s, Int times) {
    Int result = 0;

    Int length = s.length() - 1;
    Int start = 0;
    for (Int i = 0; i < length; ++i) {
        if (((1 << i) & times) != 0) {
            result += stol(s.substr(start, i - start + 1));
            start = i + 1;
        }
    }
    result += stol(s.substr(start, length - start + 1));
    return result;
}

int main(void) {
    string s;
    cin >> s;
    Int times = (1 << (s.length() - 1));
    Int result = stol(s);
    for (int i = 1; i < times; ++i) {
        result += PerseAndCalc(s, i);
    }
    cout << result << endl;
    return 0;
}

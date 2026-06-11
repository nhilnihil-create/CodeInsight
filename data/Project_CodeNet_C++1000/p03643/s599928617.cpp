#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s = "ABC";
    string N;

    cin >> N;

    s += N;

    cout << s << endl;
    return 0;
}
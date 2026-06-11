#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int counter = 0, r = 0;
    counter = s.size();
    r = counter - 2;
    cout << s[0] << r << s[counter-1] << endl;

}
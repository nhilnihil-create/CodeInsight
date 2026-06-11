#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    string s2 = to_string(s.size()-2);
    string s3 = s[0] + s2 + s[s.size()-1];
    cout << s3 << endl;
}

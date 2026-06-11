#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<map>
using namespace std;

int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    char a = toupper(s1[0]);
    char b = toupper(s2[0]);
    char c = toupper(s3[0]);
    cout << a << b << c << endl;
    return 0;
}
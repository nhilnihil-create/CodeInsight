#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    cout << (char)(s1.at(0) - 'a' + 'A') << (char)(s2.at(0) - 'a' + 'A') << (char)(s3.at(0) - 'a' + 'A') << endl;
}
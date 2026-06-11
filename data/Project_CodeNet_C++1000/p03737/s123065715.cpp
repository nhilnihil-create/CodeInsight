#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2, s3;
    char dif = 'A' - 'a';
    cin >> s1 >> s2 >> s3;
    char s11 = s1[0] + dif;
    char s22 = s2[0] + dif;
    char s33 = s3[0] + dif;
    cout << s11 << s22 << s33 << endl;
}

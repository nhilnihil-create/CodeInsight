#include <bits/stdc++.h>
using namespace std;

int main()
{
        string s1,s2,s3;
        cin >> s1 >> s2 >> s3;

        char a, b, c;
        a = s1[0];
        b = s2[0];
        c = s3[0];
        a = (a - 'a') + 'A';
        b = (b - 'a') + 'A';
        c = (c - 'a') + 'A';
        cout << a << b << c << endl;


}

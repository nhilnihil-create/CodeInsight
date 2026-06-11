#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    int sz1 = s1.size();
    int sz2 = s2.size();
    if(s1[sz1-1] == s2[0] && s2[sz2-1] == s3[0]) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
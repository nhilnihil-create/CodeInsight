#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main()
{
        string S; cin >> S;
        ll len = S.length();
        for (int i = 0; i < S.length(); i+=2) {
                len -= 2;
                string s1 = S.substr(0, len/2);
                string s2 = S.substr(len/2, len/2);
//              cout << s1 << " " << s2 << endl;
                if (s1 == s2) {
                        cout << s1.length() * 2 << endl;
                        break;
                }
        }


}

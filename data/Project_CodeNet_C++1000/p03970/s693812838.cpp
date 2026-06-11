#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main()
{
    string cf = "CODEFESTIVAL2016";
    string s;
    int c = 0;
    cin >> s;
    rep(i, 16){
        if (s[i] != cf[i])
            c++;
    }
    cout << c << endl;
}
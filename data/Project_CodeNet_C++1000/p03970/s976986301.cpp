#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    string s, t = "CODEFESTIVAL2016"; cin >> s;
    int cnt = 0;
    for(int i = 0; i < 16; i++) if(s[i] != t[i])cnt++;
    cout << cnt << endl;
}
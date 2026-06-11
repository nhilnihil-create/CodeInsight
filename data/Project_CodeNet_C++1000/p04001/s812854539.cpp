#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double pi=3.141592653589793;
typedef unsigned long long ull;
typedef long double ldouble;
const ll INF=1e18;


int main(){
    string s;
    cin >> s;
    int n = s.length();
    ll answer = 0;
    // {0, 1, ..., n-1} の部分集合の全探索
    for (ll bit = 0; bit < (1<<(n-1)); ++bit)
    {
        bitset<16> tmp(bit);
        ll cost = 1;
        /* bit で表される集合の処理を書く */
        for(int i = n-1; i > 0; i--){
            char c = s.at(i);
            answer += cost * (c - '0');
            if(tmp.test(n-1-i)) {
                cost = 1;
            }
            else cost *= 10;
        }
        answer += cost * (s.at(0) - '0');
    }
    cout << answer << endl;
}
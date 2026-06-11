#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
int INF = 1000000009;
int main()
{
    string s;
    cin >> s;
    string t = s;
    reverse(s.begin(), s.end());
    if(t == s){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
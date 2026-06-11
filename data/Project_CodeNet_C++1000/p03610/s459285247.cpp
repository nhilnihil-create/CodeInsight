// In the name of ALlah //
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 * 5 + 10 , inf = 1e9;
string s;
void solve(){
    for (int i = 0; i < s.size(); i ++){
        if (!(i & 1))
            cout << s[i];
    }
}
void in (){
    cin >> s; solve();
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
    in();
}

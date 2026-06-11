#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int n; cin >> n;
    string s; cin >> s;
    int need_left = 0;
    int pointer = 0;
    for(int i = 0; i < n; ++i){
        if(s[i] == '(') ++pointer;
        else{
            if(pointer==0)++need_left;
            else --pointer;
        }
    }
    int need_right = pointer;
    string ans = "";
    rep(i,need_left) ans += '(';
    ans += s;
    rep(i,need_right) ans += ')';
    cout << ans << endl;
}
#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

lli n;
string s;

int main(void){
    cin >> n >> s;
    lli l = 0, r = 0;
    deque<char> ans;
    rep(i, n){
        if(s[i] == '(') l++;
        else r++;
        if(l < r){
            ans.push_front('(');
            r--;
        }
        ans.push_back(s[i]);
    }
    string t;
    rep(i, ans.size()) t+=ans[i];
    while(r < l) t+=')', r++;
    cout << t << endl;
    return 0;
}

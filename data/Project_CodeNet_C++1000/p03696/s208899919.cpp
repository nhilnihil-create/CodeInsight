#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;cin >> n;
    string s;
    cin >> s;
    int m = 0;
    int cnt = 0;
    rep(i,n){
        if(s[i] == '(') cnt++;
        else cnt--;
        m = min(m,cnt);
    }
    m = abs(m);
    string t = "";
    rep(i,m) t.push_back('(');
    s = t+s;
    t = "";
    if(cnt+m>0){
        rep(i,cnt+m) t.push_back(')');
        s = s+t;
    }

    cout << s << endl;


}
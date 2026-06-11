#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main(){
    string s;
    cin >> s;
    int cnt = 1;
    rep(i,s.size()-1){
        if(s[i] != s[i+1]) cnt++;
    }
    cout << cnt - 1 << endl;
}

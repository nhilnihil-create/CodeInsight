#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pil = pair<pii,int>;


int main(){
    string s;
    cin >> s;
    int t = s.size();
    rep(i,t){
        if(i%2 == 0)cout << s[i];
    }
    return 0;
}
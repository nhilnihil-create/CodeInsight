#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();
    rep(i,s.size()){
        if(s[i]=='a') continue;
        int t = s[i]-'a';//tばんめ
        if(t+k >= 26 && k-(26-t)>=0) {
            s[i]='a';
            k-=26-t;
        }
    }
    if(k){
        int t = k%26;
        int now = s[n-1]-'a';
        now+=t;
        s[n-1]='a'+now;
    }
    cout << s << endl;
    return 0;
}
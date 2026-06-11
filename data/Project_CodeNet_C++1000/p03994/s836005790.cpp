#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

string s;
lli k;

int main(void){
    cin >> s >> k;
    rep(i, s.size()){
        if(s[i] == 'a') continue;
        lli d = 'z'-s[i]+1;
        if(k >= d){
            k-=d;
            s[i] = 'a';
        }
    }
    lli u = s[s.size()-1]-'a';
    u += k%26;
    u%=26;
    s[s.size()-1] = char('a'+u);
    cout << s << endl;
    return 0;
}

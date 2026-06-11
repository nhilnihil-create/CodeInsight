#include <bits/stdc++.h>
using namespace std;
using pint = pair<int,int>;


const long long INFLL = 1LL << 60;
const int INFI = 1000000000;


int main(){
    map<char,string> m{};
    string a,b,c; cin >> a >> b >> c;
    m['a'] = a; m['b'] = b; m['c'] = c;
    char now='a';
    char ans;
    while(true){
        string s = m[now];
        if(s.size()==0) {ans=toupper(now); break;}
        char c = s[0];
        s.erase(s.begin());
        m[now] = s;
        now = c;
    }
    cout << ans << endl;
}

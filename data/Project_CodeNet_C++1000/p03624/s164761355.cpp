#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = 1; i <= n; i++)
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }
using P = pair <int, int>;
 
ll MOD = 1000000007;
ll INF =1<<29;

char d[51][51];

int main() {
    string s;
    cin >> s;
    set<char>st;
    rep(i,s.size()) st.insert(s[i]);
    if(st.size()==26){
        cout <<"None" <<endl;
        return 0;
    }
    sort(s.begin(),s.end());
    s.erase(unique(s.begin(),s.end()),s.end());
    string t;
    for(char c = 'a';c<='z';++c){
        t.push_back(c);
    }
    rep(i,s.size()){
        if(s[i]!=t[i]){
            cout << t[i]<<endl;
            return 0;
        }       
    }
    cout << t[s.size()] <<endl;
}
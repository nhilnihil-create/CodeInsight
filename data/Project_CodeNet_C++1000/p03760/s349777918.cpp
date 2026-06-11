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

int main() {
    string s,t;
    cin >> s>>t;
    if(s.size()==t.size()){
        rep(i,s.size()){
            cout <<s[i]<<t[i];
        }
    }
    else{
         rep(i,s.size()-1){
             cout << s[i]<<t[i];
         }
         cout << s[s.size()-1];
    }
    
}
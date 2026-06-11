#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;
#define reverse(s) reverse(s.begin(),s.end())


ll gcd(ll a, ll b) {
    if (b==0) return a;
    else return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

int main(){
    map<char,int> a;
    string s;   cin >> s;

    rep(i,s.size()){
        if(!a.count(s[i])){
            a[s[i]]++;
        }else{
            cout << "no" << endl;
            return 0;
        }
    }

    cout << "yes" << endl;

    return 0;
}
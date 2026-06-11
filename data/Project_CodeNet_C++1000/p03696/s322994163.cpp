#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll a=0,b=0;
    for(ll i=0;i<n;i++){
        if(s[i]=='(') a++;
        else a--;
        if(a<0){
            a++;
            b++;
        }
    }
    for(ll i=0;i<b;i++) cout << '(';
    cout << s;
    for(ll i=0;i<a;i++) cout <<')';
}
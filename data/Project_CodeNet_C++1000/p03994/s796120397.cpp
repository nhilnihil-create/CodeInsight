#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;


int main(){
    string s;   cin >> s;
    ll k;   cin >> k;
    int n=s.size();
    for(int i=0; i<n; i++){
        int x = 26-(s[i]-'a');
        if(k<x || s[i]=='a') continue;
        s[i] = 'a';
        k -= x;
    }
    s.back() = s.back()+k%26;

    for(char c: s) cout << c;
    cout << endl;

}


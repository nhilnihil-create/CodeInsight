#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'
const int MOD = 1e9+7;

ll power(ll a, ll b){
    ll r=1;
    while(b>0){
        if(b&1)
            r=r*a %MOD;
        a = a*a %MOD;
        b/=2;
    }
    return r;
}

int main(){
    string a, b;
    cin >> a >> b;
    if(a.length() > b.length()){
        cout << "GREATER";
        return 0;
    }
    else if(a.length() < b.length()){
        cout << "LESS";
        return 0;
    }

    if(a==b)
        cout << "EQUAL";
    else if(a < b)
        cout << "LESS";
    else
        cout << "GREATER";

}

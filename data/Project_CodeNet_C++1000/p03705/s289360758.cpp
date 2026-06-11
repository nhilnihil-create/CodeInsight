#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main() {

    ll n,a,b; cin >> n >> a>> b;

    if(n == 1 && a != b) cout << 0;
    else if(a > b) cout << 0;
    else{
        cout << a+b*(n-1) - (b+a*(n-1)) + 1;
    }
    return 0;
}










#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int p = 0, q = 0, r = 0;
    for(ll b : a){
        if(b%2 != 0){
            p++;
        }
        else if(b%4 == 0){
            q++;
        }
        else{
            r++;
        }
    }
    if(r == 0){
        if(q >= p - 1) puts("Yes");
        else puts("No");
    }
    else{
        if(q >= p) puts("Yes");
        else puts("No");
    }
}
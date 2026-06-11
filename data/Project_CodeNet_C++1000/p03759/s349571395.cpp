#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll GCD(ll a, ll b){ return a ? GCD(b % a, a) : b; }
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    if(b-a==c-b) cout<<"YES";
    else cout<<"NO";
    
}
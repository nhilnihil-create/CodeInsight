#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(ll)n;i++)


int main(){
    ll a,b,c; cin >> a >> b >> c;

    if(a%2==0 && a==b && b==c){ cout << -1 << endl; return 0;}

    ll cnt=0, sum = a+b+c;
    while(a%2==0 && b%2==0 && c%2==0){
        cnt++;
        a = (sum-a)/2;
        b = (sum-b)/2;
        c = (sum-c)/2;
    }
    cout << cnt << endl;
}
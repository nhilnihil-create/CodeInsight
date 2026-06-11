#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001
#define mod 1000000007
#define pi 3.141592653589793
ll gcd(ll a,ll b){
    if(b>a) swap(a,b);
    if(b==0) return a;
    return gcd(b,a%b);
}
ll lcm(ll a,ll b){
    ll g=gcd(a,b);
    return a/g*b;
}

int main (){
    int n;
    int c_2=0;
    int c_4=0;
    cin >> n;
    rep(i,n){
        int a;
        cin >> a;
        if(a%4==0) c_4++;
        else if(a%2==0) c_2++;
        else continue;
    }
    if(c_4>=n/2) cout << "Yes" <<endl;
    else if(c_4*2+c_2>=n) cout << "Yes" <<endl;
    else cout << "No" <<endl;
    return 0;
}


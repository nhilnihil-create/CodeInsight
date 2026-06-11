#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001
#define mod 1000000007
#define pi 3.141592653589793

ll gcd(ll a,ll b){
    if(b>a) swap(a,b);
    ll r=a%b;
    while(r!=0){
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

int main (){
    ll x,y;
    cin >> x >>y;
    if(y>x){
        if(x>=0||y<=0) cout << y-x << endl;
        else cout << min(y-x,abs(y+x)+1) <<endl;
    }
    else {
        if(x==0) cout << -y+1 <<endl;
        else if(y==0) cout << x+1 <<endl;
        else if(x<0||y>0) cout << x-y+2 <<endl;
        else cout << abs(-x-y)+1 <<endl;
        }
    return 0;
}

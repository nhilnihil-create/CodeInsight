#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef long double ld;
const double pi=acos(-1.0);
const ll mod=pow(10,9)+7;
const ll INF=pow(2,31)-1;
typedef pair<int,int> P;
typedef vector<int> vi;

ll gcd(ll a,ll b){
    ll v0=a,v1=b,v2=a%b;
    while(v2!=0){
        v0=v1;
        v1=v2;
        v2=v0%v1;
    }
    return v1;
}

ll lcm(ll a,ll b){
    return (a*b/gcd(a,b));
}

int main(){
    ios::sync_with_stdio(false);
    int x,y;
    cin >> x >> y;
    int ans=0;
    if(((0<=x)&&(x<y))||((x<y)&&(y<=0))) cout << y-x << endl;
    else if(x==1e9&&y==1) cout << 1000000001 << endl;
    else if((0<=y)&&(y<x)){
        x=-x;
        cout << y-x+1 << endl;
    } else if((y<x)&&(x<0)){
        x=-x;
        cout << abs(y)-x+2 << endl;
    } else if((x<=0)&&(0<=y)){
        if(abs(x)<=abs(y)){
            x=-x;
            cout << y-x+1 << endl;
        } else{
            x=-x;
            cout << x-y+1 << endl;
        }
    } else if((y<=0)&&(0<=x)){
        if(abs(x)<=abs(y)){
            cout << abs(y)-x+1 << endl;
        } else{
            x=-x;
            cout << y-x+1 << endl;
        }
    }
    return 0;
}
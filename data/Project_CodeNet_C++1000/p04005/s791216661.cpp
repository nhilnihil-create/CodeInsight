#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define INF 1LL<<60
#define pi 3.14159265358979323846
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;} return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;} return false;}

int main(){
    ll a,b,c;cin>>a>>b>>c;

    if(!(a%2 && b%2 && c%2)){cout<<0<<endl;return 0;}

    ll MIN=min(a*b,min(b*c,c*a));

    cout<<MIN<<endl;
    return 0;
}
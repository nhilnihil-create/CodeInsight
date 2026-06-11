#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define INF 1LL<<60
#define pi 3.14159265358979323846
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;} return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;} return false;}

int main(){
    ll a,b;cin>>a>>b;
    ll ans;
    if(a<=0 && 0<=b){ans=0;}
    else if(a>0 && b>0){ans=1;}
    else{
        if((b-a+1)%2==0){ans=1;}
        else{ans=-1;}
    }

    if(ans==0){cout<<"Zero"<<endl;}
    if(ans==1){cout<<"Positive"<<endl;}
    if(ans==-1){cout<<"Negative"<<endl;}

    return 0;
}
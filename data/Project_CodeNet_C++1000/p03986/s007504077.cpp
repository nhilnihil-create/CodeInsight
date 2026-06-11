#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define INF 1LL<<60
#define pi 3.14159265358979323846
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;} return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;} return false;}

int main(){
    string x;cin>>x;
    int n=x.size();

    int s=0,t=0;
    for(int i=0;i<n;i++){
        if(x[i]=='S'){s++;}
        if(x[i]=='T'){if(t<s) t++;}
    }

    cout<<n-2*min(s,t)<<endl;
    return 0;
}
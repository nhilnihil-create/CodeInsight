#pragma GCC optimize("Ofast")
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include <bitset>
#include <cmath>
#include <limits>
#include <iostream>
#include <map>
#include<tuple>
using namespace std;
#define INF 1LL<<62
#define MAX 100000
#define MOD 1000000007
typedef long long ll;
typedef pair<int,int> P;
//typedef pair<pair<int,int>,int> p;
#define bit(n,k) ((n>>k)&1) /*nのk bit目*/
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)
struct edge{ll to,cost,val;};
template<class T,class U>bool chmin(T&a,const U&b){if(a<=b)return false;a=b;return true;}
template<class T,class U>bool chmax(T&a,const U&b){if(a>=b)return false;a=b;return true;}
//__builtin_popcount(S);
//C.erase(unique(C.begin(),C.end()),C.end());

ll A[110000],B[110000];

int main(){
    int N,K;
    cin>>N>>K;
    ll a[110000];
    for(int i=1;i<=N;i++){
        cin>>a[i];
    }
    for(int i=1;i<=N;i++){
        A[i]=A[i-1]; B[i]=B[i-1];
        A[i]+=a[i];
        if(a[i]>0){
            B[i]+=a[i];
        }
    }
    ll ans=0;
    for(int i=1;i<=N-K+1;i++){
        ll temp=0;
        temp=max(A[i+K-1]-A[i-1],0LL)+B[i-1]+(B[N]-B[i+K-1]);
        chmax(ans,temp);
    }
    cout<<ans<<endl;
    

}

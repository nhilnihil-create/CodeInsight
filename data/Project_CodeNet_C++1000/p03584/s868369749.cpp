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


int main(){
    int N,K;
    cin>>N>>K;
    int A[110000];
    ll B[110000];
    for(int i=0;i<N;i++) cin>>A[i]>>B[i];
    int n=-1;
    for(int i=0;i<=30;i++){
        if(bit(K,i)) n=i;
    }
    ll ans=0;
    for(int i=n;i>=1;i--){
        if(bit(K,i)==0) continue;
        ll temp=0;
        for(int j=0;j<N;j++){
            bool flag=true;
            for(int k=30;k>=i+1;k--){
                if(bit(K,k)==0 && bit(A[j],k)==1) flag=false;
            }
            if(bit(A[j],i)==1) flag=false;
            if(flag) temp+=B[j];
        }
        //cout<<i<<" "<<temp<<endl;
        chmax(ans,temp);
    }
    ll temp=0;
    for(int i=0;i<N;i++){
        bool flag=true;
        for(int j=0;j<=30;j++){
            if(bit(K,j)==0 && bit(A[i],j)==1) flag=false;
        }
        if(flag) temp+=B[i];
    }
    chmax(ans,temp);
    cout<<ans<<endl;
    
}

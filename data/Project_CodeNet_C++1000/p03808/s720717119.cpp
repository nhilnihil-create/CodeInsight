#pragma GCC optimize("Ofast")
#include<cstdio>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include <bitset>
#include <cmath>
#include <limits>
#include <iostream>
#include <map>
using namespace std;
#define INF 1LL<<62
#define MAX 100000
#define MOD 1000000007
typedef long long ll;
typedef pair<int,int> P;
typedef pair<pair<int,int>,int> p;
#define bit(n,k) ((n>>k)&1) /*nのk bit目*/
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)
struct edge{ll to,cost,val;};
template<class T,class U>bool chmin(T&a,const U&b){if(a<=b)return false;a=b;return true;}
template<class T,class U>bool chmax(T&a,const U&b){if(a>=b)return false;a=b;return true;}
//__builtin_popcount(S);
//C.erase(unique(C.begin(),C.end()),C.end());
//#define int ll

signed main(){
    int N;
    cin>>N;
    ll A[110000],sum=0;
    for(int i=0;i<N;i++){
        cin>>A[i];
        sum+=A[i];
    } 
    ll x=(ll)(N+1)*N/2;

    if(sum%x!=0){
        cout<<"NO"<<endl;
        return 0;
    }
    ll a=sum/x;
    ll count=0;
    bool flag=true;
    for(int i=0;i<N;i++){
        ll t=A[(i+1)%N]-A[i];
        t-=a;
        if(t>0 || (-1*t)%N!=0){
            flag=false;
        }else count+=(-1*t)/N;
    }
    if(flag && count==a) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}

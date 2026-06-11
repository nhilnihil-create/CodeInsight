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
    int N;
    cin>>N;
    ll ans=0,now=2;
    for(int i=0;i<N;i++){
        ll a;
        cin>>a;
        if(i==0) ans+=a-1;
        else{
            if(a-now<=0){
                now=max(a+1,now);
                continue;
            }
            ans+=(a-1)/now;
        }
    }
    cout<<ans<<endl;
}

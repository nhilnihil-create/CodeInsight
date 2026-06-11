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
typedef pair<ll,int> P;
typedef pair<pair<int,int>,int> p;
#define bit(n,k) ((n>>k)&1) /*nのk bit目*/
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)
struct edge{ll to,cost,val;};
template<class T,class U>bool chmin(T&a,const U&b){if(a<=b)return false;a=b;return true;}
template<class T,class U>bool chmax(T&a,const U&b){if(a>=b)return false;a=b;return true;}
//__builtin_popcount(S);
//C.erase(unique(C.begin(),C.end()),C.end());
//#define int ll

ll mycount[110000];


signed main(){
    int N;
    cin>>N;
    P a[110000];
    for(int i=0;i<N;i++){
        ll t;
        cin>>t;
        a[i].first=t;
        a[i].second=i+1;
    } 
    sort(a,a+N,greater<P>());
    int ans=N+1;
    ll now,count=0;
    a[N].first=0;
    for(int i=0;i<N;i++){
        now=a[i].first;
        while(a[i].first==now){
            ans=min(ans,a[i].second);
            i++;
            count++;
        }
        mycount[ans]+=count*(now-a[i].first);
        i--;
    }
    for(int i=1;i<=N;i++) cout<<mycount[i]<<endl;
}

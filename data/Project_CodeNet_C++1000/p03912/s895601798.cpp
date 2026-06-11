#include <bits/stdc++.h>

using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define MOD 1000000007
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 1
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)

lli data[100100];
lli cnt[100100];
lli even[100100];

signed main(){

    lli n,m;
    cin>>n>>m;

    vector<lli> v(n);
    REP(i,0,n){
        cin>>v[i];
        data[v[i]]++;
        cnt[v[i]%m]++;
    }

    REP(i,0,100010){
        even[i%m]+=data[i]/2;
    }

    lli ans=0;
    ans += cnt[0]/2;
    for(lli i=1;i<(m+1)/2;i++){
        lli a=i,b=m-i;
        if(cnt[a] > cnt[b])swap(a,b);
        ans += cnt[a];
        cnt[b]-=cnt[a];
        ans += min(cnt[b]/2,even[b]);
    }
    if(m%2==0){
        ans+=cnt[m/2]/2;
    }
    cout<<ans<<endl;


	return 0;
}
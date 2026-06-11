#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;



int main(void)
{
    long long N,K,a,b,tmp,ans=0;
    map<long long ,long long> mp;
    set<long long> S;

    cin>>N>>K;

    rep(i,N){
        cin>>a>>b;
        mp[a]+=b;
        S.insert(a);
    }

    tmp=0;
    for(auto i:S){
        tmp += mp[i];
        if(K <= tmp){
            ans=i;
            break;
        }
    }

    cout<<ans<<endl;


	return 0;
}

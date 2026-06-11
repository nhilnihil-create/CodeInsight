#include <bits/stdc++.h>
using namespace std;
#define int long long
int INF = 1e9 +7;
signed main(){
    int n,k,a,b;
    cin >>n>>k;
    vector<int> k0;
    k0.push_back(k);
    int t=1;
    while(k>=(1<<t)){
        if(k&(1<<t))k0.push_back((k -(1<<t))|((1<<t)-1));
       // cerr<<(1<<t)<<' ';
        t++;
    }
    int ans[k0.size()]={};

    //for(int i=0;i<k0.size();i++)cerr<<k0[i]<<' ';
    for(int i=0;i<n;i++){
        cin >>a>>b;
        for(int j=0;j<k0.size();j++)if((k0[j]|a)<=k0[j])ans[j]+=b;
       
    }
    int ansa=ans[0];
   // cerr<<ansa;
    for(int i=1;i<k0.size();i++){
        ansa=max(ansa,ans[i]);
      //  cerr<<ans[i];
    }
    cout <<ansa;




    return 0;
}
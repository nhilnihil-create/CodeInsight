#include <bits/stdc++.h>

using namespace std;

int INF=1e9;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;

    vector<int> p(n);
    for(int i=0;i<n;i++){
        cin>>p[i];
        p[i]--;
    }

    int ans=0;

    if(p[0]==0){
        ans++;
        int w=p[0];
        p[0]=p[1];
        p[1]=w;
    }

    for(int i=1;i<n-1;i++){
        if(p[i]==i){
            ans++;
            int w=p[i];
            p[i]=p[i+1];
            p[i+1]=w;
        }
    }

    if(p[n-1]==n-1)ans++;

    cout<<ans<<endl;

}
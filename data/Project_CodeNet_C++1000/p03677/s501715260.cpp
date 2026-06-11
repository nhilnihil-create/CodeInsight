#include<bits/stdc++.h>
using namespace std;

using ll=long long;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i],a[i]--;

    ll res=0;
    int cnt=0;
    ll sum=0;
    for(int i=0;i+1<n;i++){
        if(a[i]>a[i+1]){
            res+=m-(a[i]-a[i+1]);
            cnt++;
            sum+=m-a[i];
        }
        else res+=a[i+1]-a[i];
    }

    vector<vector<int>> vec(m);
    for(int i=0;i<n;i++) vec[a[i]].push_back(i);
    ll sub=0;
    for(int i=0;i<m;i++){
        sub=max(sub,sum-cnt);
        for(auto e:vec[i]){
            if(e==0){
                cnt++;
            }
            else{
                if(e==n-1) cnt--;
                if(a[e-1]<a[e]) sum-=a[e]-a[e-1];
                else sum-=m-(a[e-1]-a[e]);
            }
        }
        sum+=cnt;
    }
    res-=sub;
    cout<<res<<endl;

    return 0;
}
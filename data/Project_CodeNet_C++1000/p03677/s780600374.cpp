#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m,a[100005];
ll sum[200005],coe[200005],con[200005],ans=1145141919810192608;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        int l=a[i],r=a[i+1];
        if(l<r){
            sum[1]+=r-l;
            sum[l+1]-=r-l;

            coe[l+1]++;
            con[l+1]+=r+1;
            coe[r+1]--;
            con[r+1]-=r+1;

            sum[r+1]+=r-l;
            sum[m+1]-=r-l;
        }else{
            coe[1]++;
            con[1]+=r+1;
            coe[r+1]--;
            con[r+1]-=r+1;

            sum[r+1]+=m+r-l;
            sum[l+1]-=m+r-l;

            coe[l+1]++;
            con[l+1]+=m+r+1;
            coe[m+1]--;
            con[m+1]-=m+r+1;
        }
    }
    for(int i=1;i<=m;i++){
        sum[i]+=sum[i-1];
        coe[i]+=coe[i-1];
        con[i]+=con[i-1];
        ans=min(ans,sum[i]+con[i]-coe[i]*i);
    }
    cout<<ans<<endl;

    return 0;
}
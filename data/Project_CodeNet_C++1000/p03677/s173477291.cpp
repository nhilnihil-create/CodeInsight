#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> P;
const LL mod=1e9+7;
const LL LINF=1LL<<62;
const int INF=1<<17;


int imos[2*100000+2],sum[2*100000+2],mi[2*100000+2];
LL cum[2*100000+2];

int main(){
    int n,m;
    cin >> n >> m;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    LL ans=0;
    for(int i=0;i<n-1;i++){
        if(a[i+1]>a[i]){
            ans+=a[i+1]-a[i];
            imos[a[i]+2]++;
            imos[a[i+1]+1]--;
            mi[a[i+1]+1]-=a[i+1]-a[i]-1;
        }
        else{
            ans+=m-a[i]+a[i+1];
            imos[a[i]+2]++;
            imos[m+a[i+1]+1]--;
            mi[m+a[i+1]+1]-=m+a[i+1]-a[i]-1;
        }
    }
    LL s=0;
    for(int i=1;i<=2*m+1;i++){ 
        s+=imos[i];
        sum[i]+=s;
    }
    s=0;
    for(int i=1;i<=2*m+1;i++){
        s+=sum[i]+mi[i];
        cum[i]+=s;
    }
    LL maxi=0;
    for(int i=1;i<=m;i++){
        maxi=max(cum[i]+cum[i+m],maxi);
    }
    cout << ans-maxi << endl;
    return 0;
}
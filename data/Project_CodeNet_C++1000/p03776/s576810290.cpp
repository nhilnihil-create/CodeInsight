#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

int n,a,b;
double v[60];

ll comb[60][60];

ll Comb(int n,int k){
    if(k<0||n<k)return 0;
    if(n==0)return 1;
    if(comb[n][k])return comb[n][k];
    if(k<n)comb[n][k]+=Comb(n-1,k);
    if(k)comb[n][k]+=Comb(n-1,k-1);
    return comb[n][k];
}

int main(){
    cin>>n>>a>>b;
    rep(i,n)cin>>v[i];
    sort(v,v+n,greater<double>());
    double ave=0.0;
    rep(i,a)ave+=v[i];
    printf("%.10f\n",ave/a);
    int x=a-1,j=a-1;
    while(x&&v[x-1]==v[x])x--;
    while(j+1<n&&v[j]==v[j+1])j++;
    if(x){
        cout<<Comb(j-x+1,a-x)<<endl;
        return 0;
    }
    ll ans=0;
    for(int i=a;i<=b;i++)ans+=Comb(j+1,i);
    cout<<ans<<endl;
}
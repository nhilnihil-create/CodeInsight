#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int>pa;

const int N=2e5+100;
const int mod=1e9+7;

ll a[N*2];
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch))
    {
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(isdigit(ch))
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
ll pre[3*N];
ll lat[3*N];
int main()
{
    //ios::sync_with_stdio(0);cin.tie(0);
    int n=read();
    for(int i=1; i<=3*n; i++)
    {
        a[i]=read();
    }
    ll ans=-1e18;
    priority_queue<ll>q1;
    priority_queue<ll,vector<ll>,greater<ll>>q2;
    for(int j=1; j<=n; j++)
    {
        q2.push(a[j]);
        pre[j]=pre[j-1]+a[j];
    }
    //cout<<pre[2]<<endl;
    for(int i=n+1;i<=2*n;i++){
        if(a[i]>q2.top()) {
            pre[i]=pre[i-1]-q2.top()+a[i];
            q2.pop();
            q2.push(a[i]);
        }
        else pre[i]=pre[i-1];
    }

    for(int j=3*n; j>=n*2+1; j--)
    {
         lat[j]=lat[j+1]+a[j];
         q1.push(a[j]);
    }
    for(int i=n*2;i>=n;i--){
        if(a[i]<q1.top()) {
            lat[i]=lat[i+1]-q1.top()+a[i];
            q1.pop();
            q1.push(a[i]);
        }
        else  lat[i]=lat[i+1];
    }
    for(int i=n;i<=2*n;i++){
           // cout<<pre[i]<<" "<<lat[i]<<endl;
         ans=max(pre[i]-lat[i+1],ans);
    }
  cout<<ans<<endl;
return 0;
}


#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define INV 250000002
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
string str;
void add(ll &a,ll b) {a+=b;}
ll p2[MAXN],p5[MAXN];
int main()
{
    p2[0]=p5[0]=1;
    for(int i=1;i<=100000;i++) p2[i]=2LL*p2[i-1];
    for(int i=1;i<=100000;i++) p5[i]=5LL*p5[i-1];
    cin>>str;
    int n=str.size();
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        if(i!=n-1) add(ans,1LL*p2[n-2]*(str[i]-'0')*(p5[n-i-1]-1)/4);
        add(ans,1LL*(str[i]-'0')*p2[i]*p2[n-i-1]*p5[n-i-1]);
    }
    printf("%lld\n",ans);
}

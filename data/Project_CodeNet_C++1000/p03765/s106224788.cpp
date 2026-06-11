#include<bits/stdc++.h>
using namespace std;
#define y1 A2Dalek
#define y0 Cyberman
#define yn RoseTyler
#define j1 JackHarkness
#define fs first
#define sd second
const int N=5e5;
const int oo=1e9+5;
int du[]={-1,0,0,1};
int dv[]={0,-1,1,0};
const long long mod=1e9+7;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
long long sqr(long long x) {return x*x;}
int getbit(int state, int i) {return ((state>>i)&1);}

string s,t;
int q,cnt1[N+5],cnt2[N+5];
int main()
{
	//freopen("TrBBnsformBBtion.inp","r",stdin);
	//freopen("TrBBnsformBBtion.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin>>s; s=" "+s;
    cin>>t; t=" "+t;
    for (int i=1;i<s.length();i++)
    {
        cnt1[i]=cnt1[i-1];
        if (s[i]=='A') cnt1[i]++; else cnt1[i]--;
    }
    for (int i=1;i<t.length();i++)
    {
        cnt2[i]=cnt2[i-1];
        if (t[i]=='A') cnt2[i]++; else cnt2[i]--;
    }
    cin>>q;
    for (int i=1;i<=q;i++)
    {
        int l,r,u,v;
        cin>>l>>r>>u>>v;
        int val=cnt1[r]-cnt1[l-1]-(cnt2[v]-cnt2[u-1]);
        if (val%3==0) cout<<"YES"<<endl; else cout<<"NO"<<endl;
    }
	return 0;
}

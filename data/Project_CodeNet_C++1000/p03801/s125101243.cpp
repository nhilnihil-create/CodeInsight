#include<bits/stdc++.h>
using namespace std;
#define y1 A2Dalek
#define y0 Cyberman
#define yn RoseTyler
#define j1 JackHarkness
#define fs first
#define sd second
const int N=2e5;
const int oo=1e9+5;
int du[]={-1,0,0,1};
int dv[]={0,-1,1,0};
const long long mod=1e9+7;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
long long sqr(long long x) {return x*x;}
int getbit(int state, int i) {return ((state>>i)&1);}

int n;
long long ans[N+5];
ii a[N+5];
bool cmp(ii X, ii Y)
{
    if (X.fs!=Y.fs) return X.fs>Y.fs;
    return X.sd<Y.sd;
}
int main()
{
	//freopen("Frequency.inp","r",stdin);
	//freopen("Frequency.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i].fs;
        a[i].sd=i;
    }
    sort(a+1,a+1+n,cmp);
    int Min=oo;
    for (int i=1,j=1;i<=n;i++)
    {
        while (a[j].fs==a[i].fs)
        {
            Min=min(Min,a[j].sd);
            j++;
        }
        ans[Min]+=1ll*(j-1)*(a[j-1].fs-a[j].fs);
        i=j-1;
    }
    for (int i=1;i<=n;i++) cout<<ans[i]<<endl;
	return 0;
}

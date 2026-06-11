//by xxj
#include<bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
#define mp make_pair
#define ll long long
#define pii pair<int,int>
#define lowbit(x) x&-x
const int inf=1e9+7;
const double eps=1e-10;
const ll linf=1e18+7;
const ll hh=523;
//const int mod=;
ll cf[200007];
//int cfa[200007];
int a[100007];
ll ans[200007];
vector<pii> add;
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    ll sum=0;
    for (int i=1;i<n;i++){
        int x=a[i-1],y=a[i];
        if (y<x){
            y+=m;
        }
        sum+=y-x;
        add.push_back(mp(x+1,1));
        add.push_back(mp(y+1,0));
        cf[y+1]-=(y-x);
//		cout<<y<<' '<<y-x<<endl;
    }
//	cout<<sum<<endl;
    sort(add.begin(),add.end());
    int cnt=0;
    int j=1;
    for (int i=0;i<add.size();i++){
        int p=add[i].fst;
        for (int k=j;k<=p;k++){
            cf[k]+=cnt;
        }
        j=p+1;
        int t=add[i].snd;
//		cout<<p<<' '<<t<<endl; 
        if (t==1){
            cnt++;
        }
        else{
            cnt--;
        }
    }
//	cout<<cnt<<endl;
    for (int k=j;k<=2*m;k++){
        cf[k]+=cnt;
    }
//	for (int i=0;i<=2*m;i++){
//		cout<<cf[i]<<' ';
//	}
//	puts("");
    ans[0]=0;
    for (int i=1;i<=2*m;i++){
        ans[i]=ans[i-1]+cf[i];
    }
    ll mn=linf;
    for (int i=1;i<=m;i++){
        ans[i]+=ans[i+m];
//		ans[i]=sum-ans[i];
//		cout<<ans[i]<<endl;
        mn=min(sum-ans[i],mn);
    }
    printf("%lld\n",mn);
    return 0;
}
/*
input:
4 6
1 5 1 4
*/

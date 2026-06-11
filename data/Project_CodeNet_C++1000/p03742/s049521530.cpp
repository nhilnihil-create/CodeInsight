#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<queue>
#include<vector>
#include<sstream>
#include<algorithm>
#include<stack>
#include<map>
#include<set>
#define rep(i,n) for(int i=0;(i)<(n);i++)
#define rep1(i,n) for(int i=1;(i)<=(n);i++)
#define mst(a,b) memset(a,b,sizeof(a))
#define scd(a) scanf("%d",&a)
#define scdd(a,b) scanf("%d%d",&a,&b)
#define scddd(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define fr first
#define se second
#define ls x<<1
#define rs x<<1|1
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
//#define DEBUG 0
using namespace std;
const double pi=acos(-1);
const double eps=1e-6;
const ll INF=0x3f3f3f3f3f3f3f3fll;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
const int maxn=2e5+100;

void solve()
{ 
	ll x,y;
	cin>>x>>y;
	if(x<=1&&y<=1){
		printf("Brown\n");
		return ;
	}
	if(x<y)swap(x,y);
	if(x-y>=2)printf("Alice\n");
	else printf("Brown\n");         
}
int main()
{
	//freopen("D://data.txt","r",stdin);
	//freopen("D://out.txt","w",stdout);
	//IOS;
	solve();
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;;                                             ;;
	;;         ;;            ;;;;;;;;;       ;;    ;;
	;;        ;; ;;        ;;                ;;    ;;
	;;       ;;   ;;       ;;                ;;    ;;
	;;      ;;;;;;;;;      ;;                ;;    ;;
	;;     ;;       ;;     ;;                      ;;
    ;;    ;;         ;;      ;;;;;;;;;       ;;    ;;
    ;;                                             ;;
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	return 0;
}
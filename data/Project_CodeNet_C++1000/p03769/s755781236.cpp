/* ***********************************************
Author        :yang12138
Created Time  :2017年04月18日 星期二 20时30分32秒
File Name     :C.cpp
************************************************ */
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <string>
#include <math.h>
#include <cstdlib>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef pair<int,int>pii;
#define lson (root<<1)
#define rson (root<<1|1)

const int N=1005;
int ans[10000];
bool vis[50];

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

	ll n;
	scanf("%lld",&n);
	mem(ans,0);

	int tmpn=45,tot=0;

	while(n<((1LL<<tmpn)-1)) tmpn--;
	n-=(1LL<<tmpn)-1;

	for(int i=0;i<45;i++) if((n>>i)&1) vis[i]=1,tot++;

	for(int i=1;i<=tmpn+tot;i++) ans[i]=i;
	int cur1=1,cur2=tmpn+tot;

	int pre=0;
	for(int i=0;i<45;i++){
		if(vis[i]) ans[tmpn+tot+i+1+pre]=cur2--,pre++;
	}

	for(int i=tmpn+tot+1;i<=2*(tmpn+tot);i++){
		if(!ans[i]) ans[i]=cur1++;
	}

	int cnt=2*(tmpn+tot);
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++) printf("%d%c",ans[i],i==cnt?'\n':' ');
    
    return 0;
}

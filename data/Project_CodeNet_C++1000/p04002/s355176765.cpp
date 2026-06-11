#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

LL h,w;
int n;

map<pii,int> ada;

LL ans[10];

int main(){
	scanf("%lld%lld%d",&h,&w,&n);
	for(int i=1;i<=n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		for(int j=-1;j<=1;j++){
			for(int k=-1;k<=1;k++){
				int nx = a+j;
				int ny = b+k;
				if(nx < 2 || nx > h-1 || ny < 2 || ny > w-1) continue;
				ada[make_pair(nx,ny)]++;
			}
		}
	}
	LL tot = (h-2)*(w-2);
	for(auto x : ada){
		tot--;
		ans[x.second]++;
	}
	ans[0] = tot;
	for(int i=0;i<=9;i++){
		printf("%lld\n",ans[i]);
	}
	return 0;
}
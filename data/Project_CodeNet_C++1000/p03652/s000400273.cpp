#include<bits/stdc++.h>
using namespace std;

int n,m;
int adj[305][305];
int idx[305];

int cnt[305];
bool uda[305];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&adj[i][j]);
			if(j==1) cnt[adj[i][j]]++;
		}
		idx[i] = 1;
	}
	int ans = 3000;
	for(int i=1;i<=m;i++){
		int tmp = 0;
		int idd = 0;
		for(int j=1;j<=m;j++){
			if(tmp < cnt[j]){
				tmp = cnt[j];
				idd = j;
			}
		}
//		cout << ">> " << tmp << " idd " << idd << endl;
		ans = min(ans,tmp);
		uda[idd] = 1;
		if(i==m) break;
		for(int j=1;j<=n;j++){
			if(uda[adj[j][idx[j]]]){
				cnt[adj[j][idx[j]]]--;
				while(uda[adj[j][idx[j]]]){
					idx[j]++;
				}
				cnt[adj[j][idx[j]]]++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}

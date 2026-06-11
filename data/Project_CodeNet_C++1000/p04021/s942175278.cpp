#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;

int n;
int li[N+5];
int tmp[N+5];

set<int> ganjil;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&li[i]);
		tmp[i] = li[i];
	}
	sort(tmp+1,tmp+n+1);
	for(int i=1;i<=n;i+=2) ganjil.insert(tmp[i]);
	int cnt = 0;
	for(int i=1;i<=n;i+=2){
		if(ganjil.find(li[i]) == ganjil.end()) cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int N = 505;

const int M = N*N;
int x[M];

int rem[M];

int color[M];

int ret[M];

void solve(){
	int n;
	scanf("%d",&n);
	memset(color,0,sizeof(color));
	for(int i=1;i<=n;++i){
		scanf("%d",&x[i]);
		rem[i] = i-1;
		color[x[i]] = i;
	}
	vector<pair<int,int> > in;
	for(int i=1;i<=n;++i){
		in.push_back(make_pair(x[i],i));
	}
	queue<int> must;
	sort(in.begin(),in.end());
	for(int i=0;i<in.size();++i){
		int c  = in[i].second;
		for(int j=0;j<c-1;++j){
			must.push(c);
		}
	}
	queue<int> free;
	for(int i=1;i<=n*n;++i){
		if(color[i]!=0){
			int c = color[i];
			if(rem[c]!=0){
				printf("No\n");
				return;
			}
			ret[i] = c;
			for(int j=0;j<n-c;++j){
				free.push(c);
			}
			continue;
		}
		if(!must.empty()){
			int c = must.front();
			ret[i] = c;
			--rem[c];
			must.pop();
		} else if(!free.empty()){
			int c = free.front();
			ret[i] = c;
			free.pop();
		} else {
			printf("No\n");
			return;
		}
	}
	printf("Yes\n");
	for(int i=1;i<=n*n;++i){
		printf("%d ",ret[i]);
	}
	putchar('\n');
}
int main(){
	//freopen("input.txt","r",stdin);
	solve();
}
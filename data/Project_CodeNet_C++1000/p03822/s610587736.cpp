#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;
#define MAX_N 100000
typedef long long ll;
typedef pair<int, int> pii;

int N;
int lv[MAX_N+1];
int arr[MAX_N+1];
vector<int> gp[MAX_N+1];

vector<int> v;
void dfs(int x){
	lv[x] = gp[x].size();
	for(int i=0; i<gp[x].size(); i++){
		dfs(gp[x][i]);
	}
	for(int i=0; i<gp[x].size(); i++){
		v.push_back(lv[gp[x][i]]);
	}sort(v.begin(), v.end());
	int t = 1;
	while(!v.empty()){
		lv[x] = max(lv[x], v.back()+t); t++;
		v.pop_back();
	}
}

int main(){
	scanf("%d", &N);
	for(int i=2; i<=N; i++)	{
		scanf("%d", &arr[i]);
		gp[arr[i]].push_back(i);
	}
	dfs(1);
	printf("%d", lv[1]);
	return 0;
}
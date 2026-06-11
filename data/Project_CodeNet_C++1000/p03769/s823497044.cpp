#include<bits/stdc++.h>
using namespace std;

long long n;
int k;
vector<int> q;

void solve(long long n){
	if (n==1) return;
	solve(n/2);
	q.push_back(++k);
	if (n%2) q.insert(q.begin(),++k);
}

int main(){
	scanf("%lld",&n);
	solve(n+1);
	printf("%d\n",2*(int)q.size());
	for (int i=1;i<=(int)q.size();i++)
		printf("%d ",i);
	for (int i=0;i<(int)q.size();i++)
		printf("%d ",q[i]);
	printf("\n");return 0;
}
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL N;

vector<int> Ans;
vector<int>::iterator it;

int main(){
	int i,j,now;
	scanf("%lld",&N);
	for(i=39;~N>>i&1;i--);
	for(j=1;j<=i;j++)
		Ans.push_back(j);
	for(j=1;j<=i;j++)
		Ans.push_back(j);
	Ans.push_back(i+1);
	Ans.push_back(i+1);
	now=i+1;
	for(i--;~i;i--)
		if(N>>i&1){
			it=find(Ans.begin(),Ans.end(),Ans[i]);
			Ans.insert(it,now+1);
			it=find(Ans.begin(),Ans.end(),Ans[now<<1]);
			Ans.insert(it,now+1);
			now++;
		}
	printf("%d\n",Ans.size());
	for(i=0;i<Ans.size();i++)
		printf("%d ",Ans[i]);
	return 0;
}
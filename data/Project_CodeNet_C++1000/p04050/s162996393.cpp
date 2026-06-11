#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int (i) = (a);(i) < (int) (b);(i)++)
#define PB push_back
#define MP make_pair
#define ALL(x) (x).begin(),(x).end()
typedef long long ll;

int N,M;
vector<int> odd,even;

void show(vector<int>& ans)
{
	FOR(i,0,ans.size()){
		printf("%d ",ans [i]);
	}
	printf("\n");
}

int main()
{
	scanf("%d%d",&N,&M);
	FOR(i,0,M){
		int p;
		scanf("%d",&p);
		if(p & 1)
			odd.PB(p);
		else
			even.PB(p);
	}
	if(odd.size() > 2){
		printf("Impossible\n");
		return 0;
	}
	else if(M == 1){
		printf("%d\n",N);
		printf("%d\n",1 + (bool) (N - 1));
		printf("%d ",1);
		if(N - 1){
			printf("%d",N - 1);
		}
		printf("\n");
		return 0;
	}

	vector<int> ans;
	if(odd.empty() == false){
		ans.PB(odd.back());
		odd.pop_back();
	}
	FOR(i,0,even.size()){
		ans.PB(even [i]);
	}
	if(odd.empty() == false){
		ans.PB(odd.back());
		odd.pop_back();
	}

	show(ans);
	ans.front()++;
	if(--ans.back() == 0)
		ans.pop_back();
	printf("%d\n",ans.size());
	show(ans);

	return 0;
}

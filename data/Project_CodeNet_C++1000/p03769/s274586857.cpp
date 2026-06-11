#include<stdio.h>
#include<vector>
#include<deque>
using namespace std;

#define FOR(i,l,r) for(int i = (int) (l);i < (int) (r);i++)
template<typename T> bool chmax(T& a,const T& b){ return a < b ? (a = b,true) : false; }
template<typename T> bool chmin(T& a,const T& b){ return b < a ? (a = b,true) : false; }
typedef long long ll;

ll N;

int main()
{
	scanf("%lld",&N);
	N++;

	vector<int> ans;
	deque<bool> d;
	{
		ll c = N;
		while(c > 1){
			if(c & 1){
				d.push_back(true);
				ans.push_back(int(ans.size()) + 1);
			}
			d.push_back(false);
			ans.push_back(int(ans.size()) + 1);
			c >>= 1;
		}
	}

	FOR(i,0,d.size()) if(d [i] == false){
		ans.push_back(i + 1);
	}
	for(int i = int(d.size()) - 1;i >= 0;i--) if(d [i]){
		ans.push_back(i + 1);
	}

	printf("%lu\n",ans.size());
	FOR(i,0,ans.size()){
		printf("%d%s",ans [i],i == ans.size() - 1 ? "\n" : " ");
	}

	return 0;
}

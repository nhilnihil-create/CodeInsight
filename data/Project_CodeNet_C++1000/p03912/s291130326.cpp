#include<sstream>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<numeric>
#include<functional>
#include<algorithm>
using namespace std;
#define INF (1<<29)
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
#define uniq(v) v.erase(unique(all(v)),v.end())


using namespace std;


map<int, multiset<int>> mp;
int s[100000];


int main(){
	int n,m;
	cin>>n>>m;
	map<int,int> cnt;
	rep(i,n){
		int x;
		cin>>x;
		cnt[x]++;
	}
	for (auto p:cnt){
		mp[p.first%m].insert(p.second);
		s[p.first %m] += p.second;
	}
	int ans=0;

	rep(_i,m){
		int i=_i;
		int j = (m-i)%m;
		if (i==j){
			ans += s[i]/2;
			mp[i].clear();
		}
		else{
			if (s[i] > s[j]){
				swap(i,j);
			}
			while (s[i]+1 < s[j]){
				auto it = mp[j].rbegin();
				if (*it==1)break;
				int a=*it;
				mp[j].erase(mp[j].find(a));
				s[j]-=2;
				if(a)mp[j].insert(a-2);
				ans ++;
			}
			ans += min(s[i],s[j]);
			s[i] = s[j] = 0;
			mp[i].clear();
			mp[j].clear();
		}
	}

	cout<<ans<<endl;



	return 0;
}
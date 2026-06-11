#include <iostream>
#include <algorithm>
#include <vector>
#include<string>
#include <set>
#include <map>
#include <queue>
#include <limits.h>
#include <bitset>
#include <cmath>

using namespace std;

#define rip(i, n, s) for (int i = (s);i < ( int )( n ); i++)
#define all(a) (a).begin(), (a).end()
typedef long long ll;

struct P
{
	int first;
	int second;
};

P make_P(int &a,int &b){
	P ret;
	ret.first=a;
	ret.second=b;
	return ret;
}

bool operator<(const P &a, const P &b){
	if(a.first == b.first){
		return a.second < b.second;
	}
	else{
		return a.first > b.first;
	}
}

bool operator>(const P &a, const P &b){
	return b<a;
}

int main(){
	int n;
	cin >> n;
	set<P> li;
	vector<int> da(n);
	rip(i,n,0){
		cin >> da[i];
		li.insert(make_P(da[i],i));
	}
	vector<ll> ans(n);
	auto itr=li.begin();
	P now=*itr,next,maxi=now;
	int cou=1;
	ll su=0;
	rip(i,n-1,0){
		++itr;
		next=*itr;
		su+=(ll) cou*(now.first-next.first);
		if(maxi.second>next.second){
			ans[maxi.second]=su;
			su=0;
			maxi=next;
		}
		cou++;
		now=next;
	}
	ans[maxi.second]=(ll) cou*now.first + su;
	auto iit=li.begin();
	rip(i,n,0){
		printf("%lld\n",ans[i]);
		++iit;
	}
}
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;

const int DAT_SIZE=(1<<18)-1;

int data[DAT_SIZE], datb[DAT_SIZE];

void add(int a, int b, int x, int k, int l, int r){
	if(a<=l && r<=b){
		data[k]+=x;
	}else if(l<b && a<r){
		datb[k]+=(min(b, r)-max(a, l))*x;
		add(a, b, x, k*2+1, l, (l+r)/2);
		add(a, b, x, k*2+2, (l+r)/2, r);
	}
}

int sum(int a, int b, int k, int l, int r){
	if(b<=l || r<=a){
		return 0;
	}else if(a<=l && r<=b){
		return data[k]*(r-l)+datb[k];
	}else{
		int res=(min(b, r)-max(a, l))*data[k];
		res+=sum(a, b, k*2+1, l, (l+r)/2);
		res+=sum(a, b, k*2+2, (l+r)/2, r);
		return res;
	}
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	printf("%d\n", n);
	multimap<int, int> dl;
	for(int i=0; i<n; i++){
		int r, l, d;
		scanf("%d %d", &l, &r);
		d=r-l;
		dl.insert(make_pair(d, l));
	}
	int d0=0, count=0;
	auto itr=dl.begin();
	for(int d=0; d<=m-2; d++){
		while(itr->first==d){
			int l=itr->second;
			add(l, l+d+1, 1, 0, 0, m+1);
			count++;
			itr++;
		}
		int k=m/(d+2);
		int s=sum(0, k*(d+2)+1, 0, 0, m+1);
		for(int i=1; i<=k; i++){
			s-=sum((i-1)*(d+2)+1, i*(d+2), 0, 0, m+1);
		}
		printf("%d\n", n-count+s);
	}
	return 0;
}
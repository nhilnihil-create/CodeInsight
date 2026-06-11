#include <iostream>
#include <utility>
#include <algorithm>

#define MAX_N 100010
using namespace std;

int bit[MAX_N],m,l[3*MAX_N],r[3*MAX_N];
pair<int,int> p[3*MAX_N];

int sum(int i){
	int s = 0;
	while(i>0){
		s += bit[i];
		i -= i& -i;
	}
	return s;
}

void add(int i, int x){
	while(i<=m){
		bit[i] += x;
		i += i&-i;
	}
}

int main(){
	int i,n,k,j = 0;
	cin >> n >> m;
	for(i=0;i<n;i++){
		cin >> l[i] >> r[i];
		p[i] = make_pair(r[i]-l[i]+1,i);
	}
	sort(p,p+n);
	for(i=0;i<=m;i++){
		bit[i] = 0;
	}
	for(i=1;i<=m;i++){
		int ans = 0;
		while(p[j].first<i && j<n){
			add(l[p[j].second],1);
			add(r[p[j].second]+1,-1);
			j++;
		}
		ans += n-j;
		for(k=0;k<=m;k += i){
			ans += sum(k);
		}
		cout << ans << endl;
	}
}

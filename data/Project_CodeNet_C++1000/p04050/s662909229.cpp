#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1000005;

int a[N] , b[N] ,n , tot , m;

vector<int>it , p;

int main(void) {
	it.clear();
	scanf("%d%d",&n , &m);
	for(int i = 1;i <= m;i ++) scanf("%d",&a[i]);
	for(int i = 1;i <= m;i ++) {
		if(a[i] % 2) it.push_back(a[i]); else p.push_back(a[i]);
	}
	if(it.size() > 2) {
		puts("Impossible");
		return 0;
	}
	if(m == 1) {
		for(int i = 1;i <= m;i ++) cout<<a[i] <<" "; puts("");
		if(a[1] == 1) {
			puts("1");
			puts("1");
			return 0;
		}
		puts("2");
		cout<< a[1] - 1 << " " << 1 << endl;
		return 0;
	}
	else {
		while(it.size() < 2) {
			it.push_back(p[(int)p.size() - 1]); p.pop_back();
		}
		b[++ tot] = it[0] + 1;
		printf("%d " , it[0]);
		for(int i = 0;i <(int) p.size();i ++) b[++ tot] = p[i] , printf("%d " , p[i]);
		b[++ tot] = it[1] - 1;
		printf("%d " , it[1]);
		if(!b[tot]) tot --;
		printf("\n%d\n" , tot);
		for(int i = 1;i <= tot;i ++) printf("%d " , b[i]);
	}
}
#include<cstdio>
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int main(void) {
	set<int> penkis;
	for (int i = 0; i < 3; i++) {
		int penki;
		scanf("%d", &penki);
		penkis.insert(penki);
	}
	printf("%d", penkis.size());
	return 0;
}

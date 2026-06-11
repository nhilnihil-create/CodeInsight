#include<cstdio>
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int main(void) {
	int pack[3];
	for (int i = 0; i < 3; i++) {
		scanf("%d", &pack[i]);
	}
	sort(pack, pack + 3);
	if (pack[2] == pack[0] + pack[1]) printf("Yes\n");
	else printf("No\n");
	return 0;
}

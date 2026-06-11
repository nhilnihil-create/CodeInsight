#include <bits/stdc++.h>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define N 1000005
using namespace std;

int n, m, a[N];
vector < int > tek, cif, b;

int main() {
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	scanf("%d %d",&m ,&n);
	for(int i = 1; i <= n; i++){
		scanf("%d",a + i);
		if(a[i]%2)
			tek.pb(a[i]);
		else
			cif.pb(a[i]);
	}
	if((int)tek.size() > 2){
		printf("Impossible\n");
		return 0;
	}
	if((int)tek.size() >= 1){
		printf("%d ", tek[0]);
		b.pb(tek[0]);
	}
	for(int i = 0; i < cif.size(); i++){
		printf("%d ", cif[i]);
		b.pb(cif[i]);
	}
	if((int)tek.size() >= 2){
		printf("%d\n", tek[1]);
		b.pb(tek[1]);
	}
	if((int)b.size() == 1){
		if(b[0] == 1)
			printf("\n1\n1\n");
		else
			printf("\n2\n%d %d\n", b[0] - 1, 1);
		return 0;
	}
	printf("\n%d\n", n - (b[0] == 1) );
	for(int i = 0; i < b.size(); i++){
		// cout << "AMK"<<b[i]<<" ";
		if(i == 0){
			if(b[i] != 1)
				printf("%d ", b[i] - 1);
		}
		else if(i == (int)b.size() - 1)
			printf("%d\n", b[i] + 1);
		else
			printf("%d ", b[i]);
	}

	return 0;
}
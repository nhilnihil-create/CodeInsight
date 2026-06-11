#include <cstdio>
#include <algorithm>
#include <set>

#define X first
#define Y second

using namespace std;

const int N = 1e5 + 500;

int dep[N], wn[N], a[N], n;
set < pair < int, int > > S;

int main(){
	scanf("%d", &n);
	for(int i = 2;i <= n;i++){
		scanf("%d", a + i);
		wn[a[i]]++;
	}
	for(int i = 1;i <= n;i++)
		if(!wn[i]) 	S.insert({dep[i], i});
	for(int i = 0;i < n - 1;i++){
		int cur = S.begin() -> Y; S.erase(S.begin());
		dep[a[cur]] = 1 + max(dep[a[cur]], dep[cur]);
		wn[a[cur]]--;
		if(!wn[a[cur]])
			S.insert({dep[a[cur]], a[cur]});
	}
	printf("%d\n", dep[1]);
}
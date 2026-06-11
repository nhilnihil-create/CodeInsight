#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e5 + 500;

int n, s;

int main(){
	scanf("%d", &n);
	for(int i = 0;i < n;i++){
		int x; scanf("%d", &x);
		s += (x % 2);
	}
	printf(s % 2 ? "NO\n" : "YES\n");
}
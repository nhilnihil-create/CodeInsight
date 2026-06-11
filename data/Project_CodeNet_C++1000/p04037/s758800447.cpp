#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN = 100010;

int a[MAXN];

int main(){
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
		scanf("%d", &a[i]);
	sort(a + 1, a + 1 + N);
	for (int i = 1, s; i <= N; ++i){
		if (a[i] >= N - i + 1){
			if (a[i] == a[i - 1]) 
				s ^= 1;
			else if (a[i - 1] == N - i + 1) 
				s = 1 ^ (s && !((a[i] - (N - i + 1)) & 1));
			else 
				s = (a[i] - (N - i + 1)) & 1;
			if (s) printf("First");
			else printf("Second");
			break;
		}
		if (a[i] != a[i - 1])
			s = 0;
		else
			s ^= 1;
	}
	return 0;
}

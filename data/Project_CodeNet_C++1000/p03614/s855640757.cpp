#include <cstdio>
#include <algorithm>
using namespace std;

int A[100005], ans;
int main(){
	int N; scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", A + i);
	}
	for (int i = 1; i < N; i++) {
		if (A[i] == i && A[i + 1] == i + 1){
			swap(A[i], A[i + 1]);
			ans++;
		}
	}
	for (int i = 1; i <= N; i++) {
		if (A[i] == i)
			ans++;
	}
	printf("%d", ans);

}

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int N;
int A[110];
int odd1, odd2;
vector<int> ans;

int main(){
	scanf("%*d %d", &N);
	for (int i=1; i<=N; i++){
        scanf("%d", &A[i]);
        if (A[i]&1){
            if (!odd1) odd1 = A[i];
            else if (!odd2) odd2 = A[i];
            else{
                printf("Impossible\n");
                return 0;
            }
            A[i] = 0;
        }
    }
    if (odd1) {
        printf("%d ", odd1);
        ans.push_back(odd1);
    }
	for (int i=1; i<=N; i++) if (A[i]) {
        printf("%d ", A[i]);
        ans.push_back(A[i]);
	}
	if (odd2) {
        printf("%d ", odd2);
        ans.push_back(odd2);
    }
	printf("\n");
	if (N == 1){
        if (ans[0] == 1) printf("1\n1");
        else printf("2\n%d 1", ans[0]-1);
        return 0;
	}
	printf("%d\n", N - ((odd1 == 1) ? 1 : 0));
	ans[0]--, ans[N-1]++;
	for (int i=0; i<N; i++) if (ans[i]) printf("%d ", ans[i]);
	return 0;
}

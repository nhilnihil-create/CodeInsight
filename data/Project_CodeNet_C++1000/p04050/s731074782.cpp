#include<bits/stdc++.h>
using namespace std;

int N, M;
int A[102];

int main() {
    scanf("%d %d", &N, &M);

    vector<int> odd;
    for(int i = 0; i < M; i++) {
        scanf("%d", &A[i]);
        if(A[i] % 2) odd.push_back(i);
    }

    if(odd.size() > 2) {
        printf("Impossible");
        return 0;
    }

    if(odd.size()) {
        swap(A[0], A[ odd[0] ]);
    }
    if(odd.size() >= 2) {
        if(odd[1] == 0) odd[1] = odd[0];
        swap(A[M - 1], A[ odd[1] ]);
    }

    for(int i = 0; i < M; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    vector<int> sol;
    if(A[0] > 1) sol.push_back(A[0] - 1);
    for(int i = 1; i < M - 1; i++) {
        sol.push_back(A[i]);
    }
    if(M >= 2) sol.push_back(A[M - 1] + 1);
    else sol.push_back(1);

    printf("%d\n", sol.size());
    for(int i = 0; i < sol.size(); i++) {
        printf("%d ", sol[i]);
    }
}

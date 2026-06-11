#include <bits/stdc++.h>
using namespace std;

int A[100005];
int B[100005];

int main(){
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i ++){
        scanf("%d", &A[i]);
        B[i] = A[i];
    }

    sort(B, B+N);
    set<int> s;
    for(int i = 0; i < N; i += 2){
        s.insert(B[i]);
    }

    int ans = 0;
    for(int i = 0; i < N; i += 2){
        if(!s.count(A[i])){
            ans ++;
        }
    }

    printf("%d", ans);
    return 0;
}

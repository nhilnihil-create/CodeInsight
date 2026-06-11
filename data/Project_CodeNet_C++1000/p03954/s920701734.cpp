#include<bits/stdc++.h>
#define reg register

const int maxn = 2e5 + 5; //!

int N;
int A[maxn];
int B[maxn];

bool chk(int x){
        for(reg int i = 1; i <= 2*N-1; i ++) B[i] = (A[i]>x);
        for(reg int d = 1; d < N; d ++)
                if((B[N+d-1]&&B[N+d]) || (B[N-d+1]&&B[N-d])) return 1;
                else if(((!B[N+d-1])&&(!B[N+d])) || ((!B[N-d+1])&&(!B[N-d]))) return 0;
        return B[1];
}

int main(){
        scanf("%d", &N);
        for(reg int i = 1; i <= 2*N-1; i ++) scanf("%d", &A[i]);
        int l = 1, r = 2*N-1;
        while(l < r){
//                printf("%d %d\n", l, r);
                int mid = l+r >> 1;
                if(chk(mid)) l = mid + 1;
                else r = mid;
        }
        printf("%d\n", l);
        return 0;
}
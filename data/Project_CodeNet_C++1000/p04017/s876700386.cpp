#include <bits/stdc++.h>
using namespace std;

int x[100005];
int next1[100005];

int p[100005][20];

int N;

int kthparent(int x, int k){
    for(int i = 19; i >= 0; i --){
        if(k >= (1<<i)){
            x = p[x][i];
            k -= (1<<i);
            if(x == N){return x;}
        }
    }
    return x;
}

int main(){
    scanf("%d", &N);

    for(int i = 0; i < N; i ++){
        scanf("%d", &x[i]);
        //printf("x[%d]=%d\n", i, x[i]);
    }

    int L, Q;
    scanf("%d%d", &L, &Q);

    for(int k = 0; k < 20; k ++){
        for(int i = 0; i < N; i ++){
            p[i][k] = N;
        }
    }

    for(int i = 0; i < N; i ++){
        next1[i] = upper_bound(x, x+N, x[i]+L) - x - 1;
        //printf("next1[%d]=%d x[%d]+L=%d\n", i, next1[i], i, x[i]+L);
        p[i][0] = next1[i];
    }

    for(int k = 1; k < 20; k ++){
        for(int i = 0; i < N; i ++){
            if(p[i][k-1] == N){
                p[i][k] = N;
            }else{
                p[i][k] = p[p[i][k-1]][k-1];
            }
        }
    }

    for(int i = 0; i < Q; i ++){
        int a, b;
        scanf("%d%d", &a, &b);
        a --; b --;

        if(a > b){swap(a, b);}

        int lo = 0;
        int hi = N;
        while(lo < hi){
            int mid = (lo+hi)/2;
            int temp = kthparent(a, mid);
            if(temp >= b){
                hi = mid;
            }else{
                lo = mid+1;
            }
        }

        printf("%d\n", lo);

        /*for(int j = 0; j < 10; j ++){
            printf("(%d, %d): %d\n", a, j, kthparent(a, j));
        }*/
    }

    return 0;
}

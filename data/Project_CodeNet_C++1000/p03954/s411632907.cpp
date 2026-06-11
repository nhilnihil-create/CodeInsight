#include <bits/stdc++.h>
using namespace std;

int a[200005];
int b[200005];
int c[200005];
int d[200005];

int N;

bool boleh(int k){
    for(int i = 0; i < 2*N-1; i ++){
        b[i] = (a[i] < k);
    }

    queue<int> q;
    c[0] = b[0];
    c[2*N-2] = b[2*N-2];

    q.push(0);
    q.push(2*N-2);
    for(int i = 1; i < 2*N-2; i ++){
        if(b[i+1] == b[i-1] && b[i] != b[i+1]){
            c[i] = 3;
        }else{
            c[i] = b[i];
            q.push(i);
        }
    }

    while(!q.empty()){
        int u = q.front(); q.pop();
        //printf("visited %d c[%d]=%d\n", u, u, c[u]);

        if(u < 2*N-1 && c[u+1] == 3){
            c[u+1] = c[u];
            q.push(u+1);
        }

        if(u > 0 && c[u-1] == 3){
            c[u-1] = c[u];
            q.push(u-1);
        }
    }

    return c[N-1];
}

int main(){
    scanf("%d", &N);

    for(int i = 0; i < 2*N-1; i ++){
        scanf("%d", &a[i]);
        b[i] = a[i];
    }

    int lo = 1;
    int hi = 2*N;
    while(lo < hi){
        int mid = (lo+hi+1)>>1;
        if(boleh(mid)){
            hi = mid-1;
        }else{
            lo = mid;
        }
    }

    printf("%d\n", lo);
    return 0;

    for(int i = 1; i <= 2*N-1; i ++){
        printf("boleh(%d)=%d\n", i, boleh(i));
    }

    for(int i = 0; i < 2*N-1; i ++){
        b[i] = a[i];
    }

    for(int i = 0; i < N-1; i ++){
        for(int j = 0; j < 2*N-3-2*i; j ++){
            if(b[j] >= b[j+1] && b[j] <= b[j+2]){
                c[j] = b[j];
            }else if(b[j] <= b[j+1] && b[j] >= b[j+2]){
                c[j] = b[j];
            }else if(b[j+1] >= b[j] && b[j+1] <= b[j+2]){
                c[j] = b[j+1];
            }else if(b[j+1] <= b[j] && b[j+1] >= b[j+2]){
                c[j] = b[j+1];
            }else if(b[j+2] >= b[j] && b[j+2] <= b[j+1]){
                c[j] = b[j+2];
            }else if(b[j+2] <= b[j] && b[j+2] >= b[j+1]){
                c[j] = b[j+2];
            }
        }

        for(int j = 0; j <= i; j ++){
            printf("  ");
        }

        for(int j = 0; j < 2*N-3-2*i; j ++){
            b[j] = c[j];
            printf("%d ", b[j]);
        }
        printf("\n");
    }

    printf("%d", b[0]);
    return 0;
}

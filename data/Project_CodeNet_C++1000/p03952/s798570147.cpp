#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, x;
    scanf("%d%d", &N, &x);

    if(x == 1 || x == 2*N-1){
        printf("No\n");
        return 0;
    }else{
        printf("Yes\n");
    }

    int cnt = (x+N-1)%(2*N-1);
    for(int i = 0; i < 2*N-1; i ++){
        printf("%d\n", cnt+1);
        cnt = (cnt+1)%(2*N-1);
    }

    return 0;
}

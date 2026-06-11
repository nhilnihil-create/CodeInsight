#include<bits/stdc++.h>
#define MAXN 211111
using namespace std;
int num[MAXN], N, tmp[MAXN];
int main(){
    cin>>N;
    int i, l = 1, r = 2 * N;
    for(i = 1;i <= 2 * N - 1; i++){
        scanf("%d", &num[i]);
    }
    int ans = 0;
    while(l <= r){
        int mid = (l + r) >> 1;
//		printf("mid=%d\n", mid); 
        for(i = 1;i <= 2 * N - 1; i++){
            tmp[i] = (num[i] >= mid?1 : 0);
   //         printf("%d ", tmp[i]);
        }                                  
//        puts("");
        bool flag = false, ok = false;
        for(i = 1;i < N; i++){
            if(tmp[N-i] == tmp[N-i+1]){
                if(tmp[N-i] == 1){
                    flag = ok = true;
                    break;
                }
                else {
                    ok = true;
                    break;
                }
            }
            if(tmp[N+i] == tmp[N+i-1]){
                if(tmp[N+i] == 1){
                    ok = flag = true;
                    break;
                }
                else {
                    ok = true;
                    break;
                }
            }
        }
//        printf("ok=%d flag=%d\n", ok, flag);
        if(ok == false){
        	if((tmp[N] == 0 && !(N & 1)) || (tmp[N] == 1 && N & 1 == 1))flag = true;	
        }
//    	printf("flag'=%d\n", flag);
        if(flag){
            ans = max(ans, mid);
            l = mid + 1;
        }
        else r = mid - 1;
    }
    printf("%d\n", ans);
    return 0;
}
/*
写题目习惯不太好
不把该注意的条件写下来
4
4 1 5 2 6 3 7
*/ 
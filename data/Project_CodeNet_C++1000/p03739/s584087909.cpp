#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll Num[111111];
ll Sum[111111];
ll Out1, Out2;



int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%lld", &Num[i]);

    for(int i = 1; i <= n; i++){
        Sum[i] = Sum[i - 1] + Num[i];
        if(i % 2 == 0){
            if(Sum[i] >= 0){
                Out1 += (Sum[i] + 1);
                Sum[i] = -1;
            }
        }
        else{
            if(Sum[i] <= 0){
                Out1 += (1 - Sum[i]);
                Sum[i] = 1;
            }
        }
    }

    memset(Sum,0,sizeof(Sum));
    for(int i = 1; i <= n; i++){
        Sum[i] = Sum[i - 1] + Num[i];
        if(i % 2 == 1){
            if(Sum[i] >= 0){
                Out2 += (Sum[i] + 1);
                Sum[i] = -1;
            }
        }
        else{
            if(Sum[i] <= 0){
                Out2 += (1 - Sum[i]);
                Sum[i] = 1;
            }
        }
    }
    printf("%lld\n", min(Out1, Out2));
    return 0;
}

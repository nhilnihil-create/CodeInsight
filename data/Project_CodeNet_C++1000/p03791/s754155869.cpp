#include <bits/stdc++.h>
int N,Now;
const int MO = 1e9+7;
using namespace std;
int main(){
    scanf("%d",&N);
    long long Ans = 1;
    int P = N;
    for(int i=1,j=1; i<=N; i++,j++){
        scanf("%d",&Now);
        if(Now>=j*2-1) continue;
        Ans = Ans*j%MO;
        P--; j--;
    }
    for(; P; P--)
        Ans = Ans*P%MO;
    printf("%d",(int)Ans);
}

#include <bits/stdc++.h>
using namespace std;

long long A[100005];

int main(){
    long long M;
    scanf("%lld", &M);

    long long sum = 0;
    for(int i = 0; i < M; i ++){
        scanf("%lld", &A[i]);
        sum += A[i];
    }

    if( sum%(M*(M+1)/2) != 0){
        printf("NO");
        return 0;
    }

    long long N = sum / (M*(M+1)/2);

    bool legit = true;
    for(int i = 0; i < M; i ++){
        long long temp = (A[(i+1)%M] - A[i] - N);
        temp = -temp;
        if(temp % M != 0 || temp < 0){
            legit = false;
            break;
        }else{
        }
    }

    if(legit){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    return 0;
}

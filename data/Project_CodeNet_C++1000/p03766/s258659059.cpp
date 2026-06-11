#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

const long long MOD = 1e9 + 7;
const int maxN = 1e6 + 11;

int N;
long long f[maxN],t[maxN];
int A[maxN],C[maxN];

void find(int v,int n){
//    cout << "Find to v = " << v << endl;//
    if(v > n){
        //cout << " - ";
        //for(int i = 1; i <= n; ++i) cout << A[i] << " ";
        // /cout << endl;
        ++C[n];
        return ;
    }
    A[v] = 1;
    find(v + 1,n);
    for(int x = 2; x <= n - v; ++x){
        A[v] = x;
        for(int i = 1; i <= x; ++i){
            A[i + v] = 1;
        }
        find(x + v + 1,n);
    }
}

void build(int v = 1){
    if(v > N){
        for(int i = 1; i <= N; ++i) cout << A[i] << " ";
        cout << " ~> end with " << A[N] << endl; 
        return ;
    }
    for(int i = 1; i <= N; ++i){
        A[v] = i;
        if(i > 1){
            if(v == N){
                build(v + 1);
                continue;
            }
            for(int j = 1; j <= N; ++j){
                for(int k = v + 1; k <= v + i; ++k){
                    A[k] = j;
                }
                if(j > 1){
                    for(int k = v + 1; k <= N; ++k) A[k] = j;
                    build(N + 1);
                }else  build(v + i + 1);
            }
        }else build(v + 1);
    }
}
int main(){
    
    scanf("%d",&N);

    //build();
    
    if(N == 1){
        printf("1");
    }else if(N == 2) printf("4");
    else{
        // main
    
        f[0] = t[0] = 1;
        for(int i = 1; i <= N; ++i){
            if(i <= 2) f[i] = 1;
            else{
                f[i] = (f[i - 1] + t[i - 3]) % MOD;
            }
            t[i] = (t[i - 1] + f[i]) % MOD;
 //           find(1,i);
        }
        //
        long long res = 0;
        for(int i = 1; i < N; ++i){
            int xmin = N - i;
            if(i == N - 1) ++xmin;
            res = (res + (f[i - 1] * (N - xmin + 1)) % MOD) % MOD;
            //cout << "at pos = " << i << " ~> " << xmin << " & " << (f[i - 1] * (N - xmin + 1)) % MOD << endl;
        }
        res = (res + f[N - 1]) % MOD;

        //

        //cout << "Res = " << res << endl;

        long long cnt = 0;
        for(int i = 1; i < N; ++i){
            long long tmp = ((f[i - 1] * (N - 1)) % MOD * (N - 1)) % MOD;
            cnt = (cnt + tmp) % MOD;
        }
        cnt = (cnt + (f[N - 1] * (N - 1)) % MOD) % MOD;
        //cout << "cnt = " << cnt << endl;
        printf("%lli",(res + cnt) % MOD);
    }

    return 0;
}
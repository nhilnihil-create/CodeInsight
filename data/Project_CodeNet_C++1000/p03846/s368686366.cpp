#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <cstring>
#include <cmath>
using namespace std;
#define MAXH 1000000001
#define MAXW 1000000007
#define INF 1000000007
#define MAXN 100001
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> P;


template<typename T>
T pow(T i, T n){
    T re;
    if(n == 0) return 1;
    re = pow(i, n / 2);
    if(n % 2 == 0){
        return re * re;
    }else{
        return i * re * re;
    }
}

template<typename T>
T mod_pow(T i, T n, T m){
    T re;
    if(n == 0) return 1;
    re = mod_pow(i, n / 2, m);
    if(n % 2 == 0){
        return (re * re) % m;
    }else{
        return ((i * re % m) * re) % m;
    }
}


long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int N;
int A[MAXN];

int main(){
    cin >> N;
    for(int i = 0;i < N;i++){
        cin >> A[i];
    }

    sort(A, A + N);

    bool flag = false;
    if(N % 2){
        if(A[0] != 0) flag = true;
        for(int i = 1;i < N;i += 2){
            if(A[i] != A[i + 1] || A[i] != i + 1){
                flag = true;
            }
        }
    }else{
        for(int i = 0;i < N;i += 2){
            if(A[i] != A[i + 1] || A[i] != i + 1){
                flag = true;
            }
        }
    }

    if(flag){
        printf("0\n");
        return 0;
    }else{
        printf("%lld\n", mod_pow<ll>(2, N / 2, MOD));
        return 0;
    }
}
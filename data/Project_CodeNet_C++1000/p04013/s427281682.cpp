#include <bits/stdc++.h>
//8:36 min
using namespace std;

const int N = 55;

const int mod = 1e9+7;

int n;
int A;
int a[N];
long long mem[N][N][N*N];

long long go(int idx , int lft , int sum){
    if(idx == n+1){
        return sum == 0 && lft == 0;
    }
    long long &ret = mem[idx][lft][sum];
    if(~ret)
        return ret;
    ret = 0;
    if(a[idx] <= sum && lft)
        ret += go(idx + 1 , lft - 1 , sum - a[idx]);
    ret += go(idx + 1 , lft , sum);
    return ret;
}

int main(){
    scanf("%d%d" , &n , &A);
    for(int i = 1; i <= n; i++){
        scanf("%d" , &a[i]);
    }
    memset(mem , -1 , sizeof mem);
    long long ans = 0;
    for(int len = 1; len <= n; len++){
        ans += go(1 , len , A*len);
    }
    printf("%lld\n" , ans);
}

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
typedef pair<ll, ll> P;


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
ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

ll N, x;
ll A[MAXN], B[MAXN] ;

int main(){
    string S;
    cin >> S;
    int length = S.length();
    bool flag = true;//true :first, false :second 
    if(length % 2 == 0) flag = false;
    if(S[0] == S[length - 1]) flag = !flag;
    if(flag) printf("First\n");
    else printf("Second\n");
    return 0;
}
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
#define MAXW 101
#define INF 1000
#define MAXN 1001
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
ll solve(ll a, ll x){
    if(x % a == 0) return x;
    return (x / a + 1) * a;
}

ll N;
ll T[MAXN], A[MAXN];

int main(){
    string s;
    cin >> s;
    map<char, int> m;
    m['p'] = m['g'] = 0; 
    int win = 0, lose = 0;

    for(int i = 0;i < s.length();i++){
        if(s[i] == 'g'){
            if(m['p'] < m['g']){
                m['p']++;
                win++;
            }else{
                m['g']++;
            }
        }else{
            if(m['p'] < m['g']){
                m['p']++;
            }else{
                m['g']++;
                lose++;
            }
        }
    }

    printf("%d\n", win - lose);

    return 0;
}


        
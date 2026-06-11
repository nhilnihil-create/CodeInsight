#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 105;

const int mod = 1e9+7;

int n;

vector < ll > primeFactors(long long num){
    vector < ll > prm;
    while (num % 2 == 0){
        prm.push_back(2);
        num = num/2;
    }
    for (ll i = 3; i*i <= num; i = i + 2){
        while (num % i == 0){
            prm.push_back(i);
            num = num/i;
        }
    }
    if (num > 2)
        prm.push_back(num);
    return prm;
}

int main() {
    scanf("%d" , &n);
    map < int , int > cnt;
    for(int i = 1; i <= n; i++){
        vector < ll > f = primeFactors(i);
        for(auto v : f){
            cnt[v]++;
        }
    }
    long long ans = 1;
    for(auto it = cnt.begin(); it != cnt.end(); it++){
        ans = (ans * ((it->second) + 1)) % mod;
    }
    printf("%lld\n" , ans);
    return 0;
}

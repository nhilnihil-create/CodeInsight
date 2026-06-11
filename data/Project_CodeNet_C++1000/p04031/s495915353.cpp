#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+5;

const int mod = 1e9+7;

int n;
int ar[N];

long long get(int x){
    long long cost = 0;
    for(int i = 1; i <= n; i++){
        cost += (x - ar[i]) * (x - ar[i]);
    }
    return cost;
}

int main(){
    cin >> n;
    long long av = 0;
    for(int i = 1; i <= n; i++){
        cin >> ar[i];
        av += ar[i];
    }
    av /= n;
    printf("%lld\n" , min(get(av) , get(av + 1)));
}
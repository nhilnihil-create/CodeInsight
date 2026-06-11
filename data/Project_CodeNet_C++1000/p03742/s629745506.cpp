#include<cstdio>
#include<string.h>
#include<algorithm>
#include<string>
#include<cmath>
#include<iostream>
#define ll long long
using namespace std;

ll Abs(ll x){
    if(x < 0) return -x;
    return x;
}

int main() {
    ll x, y;
    while(scanf("%lld %lld", &x, &y) != EOF) {
        long long temp = Abs(x - y);
        if(temp <= 1) printf("Brown\n");
        else printf("Alice\n");
    }
    return 0;
}

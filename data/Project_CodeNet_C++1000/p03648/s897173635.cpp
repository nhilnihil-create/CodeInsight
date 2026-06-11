
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned ll
#define db double
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define PII pair<int, int>

using namespace std;

ll k;
ll n=50;

ll f(ll i) {
    if (k%n==0) return k/n;
    if (i>=k%n) return k/n;
    return k/n+1;
}

int main() {
    scanf("%lld",&k);
    printf("%lld\n",n);
    for (ll i=0;i<n;i++) {
        printf("%lld ",(n+1)*f(i)-k+i);
    }
    printf("\n");
}
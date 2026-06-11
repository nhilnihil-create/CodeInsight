#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <iostream>
#include <set>
#include <map>
#include <string>

using namespace std;

#define mod 1e9+7
#define ll long long int
#define epsilon 1e-7

ll min(ll x, ll y){
    if(x<y)return x;
    return y;
}

int main(void){
    ll x, y;
    scanf("%lld %lld", &x, &y);
    if(x-y <= 1 && y-x <= 1)printf("Brown\n");
    else printf("Alice\n");
    return 0;
}
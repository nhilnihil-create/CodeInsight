#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef pair<pii, pii> piipii;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define eb emplace_back

int main(){
    ll x, y;
    scanf("%lld%lld", &x, &y);
    if(abs(x-y) <= 1) printf("Brown\n");
    else printf("Alice\n");
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll x,y;
    scanf("%lld%lld",&x,&y);
    if(abs(x-y)>1ll)
        printf("Alice\n");
    else
        printf("Brown\n");
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int maxn=1e5+100;

typedef long long ll;

int main()
{
    //freopen("in.txt","r",stdin);
    ll x,y;
    scanf("%lld %lld",&x,&y);
    if(x-y>=2||y-x>=2) printf("Alice");
    else  printf("Brown");
}

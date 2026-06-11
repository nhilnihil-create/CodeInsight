#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,t;
ll last, Now;
ll Out;

int main(){
    scanf("%lld%lld", &n, &t);
    for(int i = 1; i <= n; i++){
       scanf("%lld", &Now) ;
       if(last + t > Now) Out += (Now - last);
       else Out += t;
       last = Now ;
    }
    printf("%lld", Out + t);
    return 0;

}

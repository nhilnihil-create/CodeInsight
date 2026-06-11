#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <time.h>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <string.h>

#define sf scanf
#define pf printf
#define lf double
#define ll long long
#define p123 printf("123\n");
#define pn printf("\n");
#define pk printf(" ");
#define p(n) printf("%d",n);
#define pln(n) printf("%d\n",n);
#define s(n) scanf("%d",&n);
#define ss(n) scanf("%s",n);
#define ps(n) printf("%s",n);
#define sld(n) scanf("%lld",&n);
#define pld(n) printf("%lld",n);
#define slf(n) scanf("%lf",&n);
#define plf(n) printf("%lf",n);
#define sc(n) scanf("%c",&n);
#define pc(n) printf("%c",n);
#define gc getchar();
#define re(n,a) memset(n,a,sizeof(n));
#define len(a) strlen(a)
using namespace std;

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <time.h>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <string.h>

#define sf scanf
#define pf printf
#define lf double
#define ll long long
#define p123 printf("123\n");
#define pn printf("\n");
#define pk printf(" ");
#define p(n) printf("%d",n);
#define pln(n) printf("%d\n",n);
#define s(n) scanf("%d",&n);
#define ss(n) scanf("%s",n);
#define ps(n) printf("%s",n);
#define sld(n) scanf("%lld",&n);
#define pld(n) printf("%lld",n);
#define slf(n) scanf("%lf",&n);
#define plf(n) printf("%lf",n);
#define sc(n) scanf("%c",&n);
#define pc(n) printf("%c",n);
#define gc getchar();
#define re(n,a) memset(n,a,sizeof(n));
#define len(a) strlen(a)
using namespace std;
ll c[100005];
ll n,b,a,x;

bool f(ll y){
    ll all = y*b;
    for(ll i = n-1; i >= 0; i --){
        if(c[i] > all){
            y -= (c[i]-all)/a;
            if(c[i] - ((c[i]-all)/a)*a-all > 0){
                y --;
            }
            if(y < 0){
                return false;
            }
        }else{
            return true;
        }
    }
    return true;
}
int main(){

    sld(n) sld(a) sld(b)

    a -= b;
    for(ll i = 0; i < n; i ++){
        sld(c[i])
    }
    sort(c,c+n);
    //p(f(2));
    ll l = 0,r = 1000000000;
    ll mid;
    while(l < r){
        //p(mid) pn
        mid = (l+r)>>1;
        if(!f(mid)){
            l = mid+1;
        }else{
            r = mid;
        }
    }
    pld(l) pn
    //p(c[0]) pn
    return 0;
}

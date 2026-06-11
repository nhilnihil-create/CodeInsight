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
//https://codeforces.com/contest/1213/problems
//https://codeforces.com/contest/1213/submit
ll a[300000];
ll b[300000];
ll aabs(ll a){
    if(a < 0){
        return a*-1ll;
    }else{
        return a;
        }
}
int main(){
    int n;
    s(n)
    ll sum = 0;
    for(int i = 0; i < n; i ++){
        sld(a[i])
        sum += a[i];
        b[i] = sum;
    }
    ll mini = 3000000000ll;
    for(int i = 0; i < n-1; i ++){
        mini = min(aabs(2ll*b[i]-sum),mini);
        //p(aabs(2ll*b[i]-sum)) pn
    }
    pld(mini) pn




    return 0;
}

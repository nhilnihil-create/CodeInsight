#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}

int main() {
    int n;
    cin >> n;
    int a[n];
    int flag = 0;
    rep(i,n)cin >> a[i];
    sort(a,a+n);
    if(a[0]==a[n-1]){
        if(a[0]==n-1)flag=1;
        if(a[0] <= n/2)flag=1;
    }
    if(a[0]+1 == a[n-1]){
        int count = 0;
        rep(i,n){
            if(a[i] == a[0])count++;
        }
        int k = a[n-1];
        n -= count;
        k -= count;
        if(a[0]>=count){
            if(k <= n/2)flag = 1;
        }
    }

    if(flag>0)yn;
    return 0;
}
 
 

#include <iostream>
#include <vector>
//#include <string>
#include <algorithm>
//#include <math.h>
//#include <queue>
//#include <stack>
//#include <iomanip>

// sometimes used
//#include <set>
//#include <map>
//#include <numeric>
//#include <list>
//#include <deque>
//#include <unordered_map>

typedef long long LL;
//typedef long double LD;
using namespace std;
 
//#define MOD 1000000007
//#define MAX 10000100
//#define NIL -1

int main() {
    LL n;
    LL x;
    cin >> n >> x;
    vector<LL> a(n);
    vector<LL> a_sum(n-1);
    LL ans=0;

    for(LL i=0; i<n; i++){
        cin >> a[i];
    }

    for(LL i=0; i<n; i++){
        if(a[i]>x){
            ans+=a[i]-x;
            a[i]=x;
        }
    }

    for(LL i=0; i<n-1; i++){
        a_sum[i]=a[i]+a[i+1];
    }

    for(LL i=0; i<n-1; i++){
        LL tmp;
        if(a_sum[i]>x && a_sum[i+1]>x){
            tmp=min(a_sum[i]-x, a_sum[i+1]-x);
            ans+=tmp;
            a_sum[i]-=tmp;
            a_sum[i+1]-=tmp;
        }
    }

    for(LL i=0; i<n-1; i++){
        if(a_sum[i]>x){
            ans+=a_sum[i]-x;
        }
    }

    cout << ans << endl;

    return 0;
}

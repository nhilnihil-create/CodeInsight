#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <iomanip>
#include <set>
#include <ctime>
#include <tuple>
#include <bitset>
using namespace std;

/*
sort(sp.begin(), sp.end(), [](PAIR l, PAIR r){
        return l.first<r.first || (l.first==r.first && l.second > r.second);
        });
*/

typedef long long  ll;

#define fi first
#define se second


int main() {
    int n,k;
    cin>>n>>k;
    vector<ll>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll ans=100000000000;
    for(ll bit=0;bit<(1<<n);bit++){
        if(__builtin_popcount(bit)<k)continue;
        ll cnt=0;
        ll tmp_max=0;
        for(ll i=0;i<n;i++){
            if(a[i]>tmp_max){
                tmp_max=a[i];
                continue;
            }
            if(bit&(1<<i)){
                cnt+=(tmp_max-a[i]+1);
                tmp_max++;
            }
        }
        ans=min(ans,cnt);
    }
    cout<<ans<<endl;




    return 0;
}

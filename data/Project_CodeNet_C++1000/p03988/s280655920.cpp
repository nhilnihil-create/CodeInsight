#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#define mkp(a, b) make_pair(a, b)
#define pb(t) push_back(t)
#define ft first
#define sc second
#define pt(num) cout << num << "\n"
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
#define max(a, b) ((a)>(b) ? (a):(b))
#define min(a, b) ((a)<(b) ? (a):(b))
#define chmax(a, b) (a<b ? a=b : 0)
#define chmin(a, b) (a>b ? a=b : 0)
#define INF 1000000000000000000
#define MOD 1000000007LL
#define MAX 101010
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef map<ll, ll> Map;




int main(void) {
    ll N;
    cin >> N;
    ll cnt[111]={};
    ll i;
    ll R=0;
    
    for(i=0; i<N; i++) {
        ll a;
        cin >> a;
        chmax(R, a);
        cnt[a]++;
    }
    
    ll min=-1;
    if(R%2==0) {
        min=R/2;
        for(i=R; i>=min+1; i--) {
            if(cnt[i]<2) {
                puts("Impossible");
                return 0;
            }
            cnt[i]-=2;
        }
        if(cnt[R/2]!=1) {
            puts("Impossible");
            return 0;
        }
        cnt[R/2]=0;
    }else {
        min=R/2+1;
        for(i=R; i>=min; i--) {
            if(cnt[i]<2) {
                puts("Impossible");
                return 0;
            }
            cnt[i]-=2;
        }
    }
    
    for(i=0; i<=min; i++) {
        if(cnt[i]) {
            puts("Impossible");
            return 0;
        }
    }
    
    puts("Possible");
    
}







 #include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <stdio.h>
#include <list>
#include <numeric>
#include <stack>
#include <queue>
#include <tuple>
#include <bitset>
#include <map>
#include <math.h>
//ceil(a/b)   (a + (b - 1))/ b
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
typedef long long ll;
typedef pair<int,int> P;
const int inf=1000000007;
const ll mod=1000000007;
const double PI=3.14159265358979323846;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};


int main(){
    int N,K;
    cin >> N >> K;
    ll a[N];
    rep(i,N) cin >> a[i];

    ll ans = 1000000000000;
    for(int bit=0; bit < (1<<N); bit++) {
	vector<bool> ch;
	int num = 0;
	ll pre = 0;
	ll tmp = 0;
	rep(i,N) {
	    if(bit & (1<<i)) {
		ch.push_back(true);
		num++;
	    }
	    else ch.push_back(false);
       	}
	if(num<K) continue;

	rep(i,N) {
	    if(ch[i]) {
		if(pre >= a[i]) {
		    pre++;
		    tmp += pre - a[i];
		}
	    }
	    pre = max(pre,a[i]);
	}
	ans = min(ans,tmp);
    }
    cout << ans << endl;
					 
    
    return 0;
}


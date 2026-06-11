
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<math.h>
#include<string>
#include<string.h>
#include<stack>
#include<queue>
#include<vector>
#include<utility>
#include<set>
#include<map>
#include<stdlib.h>
#include<iomanip>

using namespace std;

#define ll long long
#define ld long double
#define EPS 0.0000000001
#define INF 1e9
#define MOD 1000000007
#define rep(i,n) for(i=0;i<(n);i++)
#define loop(i,a,n) for(i=a;i<(n);i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
#define int ll
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;

signed main(void) {
    int i,j;
    int n,k;

    cin >> n >> k;
    vi a(n),b(n);
    rep(i,n) cin >> a[i] >> b[i];
    int ans = 0;
    rep(i,31){
        //cout << "! " << i << endl;
        //kのiビット目を0にする, iビット目以下はkを超えない範囲でできるだけ1を立てる
        int bit = 0;
        for(j = 30; j > i; j--)
            if(k & (1 << j))
                bit += 1 << j;

        for(j = i - 1; j >= 0; j--)
            if((bit + (1 << j)) <= k)
                bit += 1 << j;

        if(bit > k)continue;

        int tmp = 0;
        rep(j,n){
            if(bit == (bit | a[j])){
                tmp += b[j];
                //cout << j << endl;
            }
        }
//        cout << "? " << bit << " " << tmp << endl;
        ans = max(ans, tmp);
    }

    cout << ans << endl;

}

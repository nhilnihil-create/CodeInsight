#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAX = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000007;
const double PI=3.1415926535897932;

ll N, ans1=0, ans2=0, tmp=0;
vector<ll> A;

signed main(){
    for(int i=0;i<7;i++) {
        ll a;
        cin >> a;
        A.push_back(a);
    }
    ans1 += A[1];
    ans2 += A[1];
    if(A[0]>0&&A[3]>0&&A[4]>0) {
        A[0]--;
        A[3]--;
        A[4]--;
        ans1 += 3;
        ans1 += A[0]/2*2;
        ans1 += A[3]/2*2;
        ans1 += A[4]/2*2;
        A[0]++;
        A[3]++;
        A[4]++;
    }
    ans2 += A[0]/2*2;
    ans2 += A[3]/2*2;
    ans2 += A[4]/2*2;
    cout << max(ans1, ans2) << endl;
    return 0;
}
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define bit(n) (1<<(n))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
int const INF = 1001001001;


int main()
{
cin.tie(0);
ios::sync_with_stdio(false);

int N;
cin >> N;
vl A(N);
rep(i,N) cin >> A[i];

ll cnt = 0;
ll sum = 0;
rep(i,N) {
    sum += A[i];
    if(i % 2 == 0) {
        if(sum > 0) continue;
        cnt += 1 - sum;
        sum = 1;
    }
    if(i % 2 == 1) {
        if(sum < 0) continue;
        cnt += sum + 1;
        sum = -1;
    }
}

ll cnt1 = 0;
ll sum1 = 0;
rep(i,N) {
    sum1 += A[i];
    if(i % 2 == 1) {
        if(sum1 > 0) continue;
        cnt1 += 1 - sum1;
        sum1 = 1;
    }
    if(i % 2 == 0) {
        if(sum1 < 0) continue;
        cnt1 += sum1 + 1;
        sum1 = -1;
    }
}
cout << min(cnt, cnt1) << endl;
return 0;
}
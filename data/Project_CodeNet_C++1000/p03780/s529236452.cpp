#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int const MAX_N = 5005;
int const MAX_S = 5005;

bool dp[MAX_N][MAX_S];
int n,k;
vector<int> a;
bool need(int x) {
    Fill(dp, false);
    dp[0][0] = 1;
    rep(i,n) {
        rep(j,k) {
            if(!dp[i][j]) continue;
            dp[i+1][j] = 1;
            if(i == x) continue;
            if(j + a[i] < k) dp[i+1][j + a[i]] = 1;
        }
    }
    bool ok = false;
    rep(j,k) if(dp[n][j] && j + a[x] >= k) ok = true;
    return ok;
}


int main()
{
    cin >> n >> k;
    a.resize(n);
    rep(i,n) {
        cin >> a[i];
        chmin(a[i],k);
    }
    sort(a.begin(),a.end());

    int l = -1, r = n;
    while(r - l > 1) {
        int mid = (l + r)/2;
        if(need(mid)) r = mid;
        else l = mid;
    }

    cout << r << endl;
    return 0;
}
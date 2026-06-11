#include<bits/stdc++.h>
using namespace std;

#define lint long long
#define P pair<int, int>
#define LLP pair<long long, long long>
#define REP(i, x, n) for(int i = (x), i##_len = (int)(n) ; i < i##_len ; ++i)
#define rep(i, n) for(int i = 0, i##_len = (int)(n) ; i < i##_len ; ++i)
#define repr(i, n) for(int i = (int)(n) - 1 ; i >= 0 ; --i)
#define SORT(x) sort((x).begin(), (x).end())
#define SORT_INV(x) sort((x).rbegin(), (x).rend())

const int IINF = (1 << 30) - 1;
const long long LLINF = 1LL << 61;
const long long MOD = 1000000007LL;
const int dx4[] = {1, 0, -1, 0}, dy4[] = {0, 1, 0, -1};
const int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[] = {0, -1, -1, -1, 0, 1, 1, 1};
const double EPS = 1e-8;

int n;
vector<int> a;

bool check(int mid){
    int l1 = 0, r1 = n * 2, l0 = 0, r0 = n * 2;
    if(a[0] >= mid){
        l1 = 1;
    }else{
        l0 = 1;
    }
    if(a[n * 2 - 2] >= mid){
        r1 = n * 2 - 1;
    }else{
        r0 = n * 2 - 1;
    }

    for(int i = n - 1 ; i > 0 ; --i){
        if(a[i] >= mid && a[i - 1] >= mid){
            l1 = i + 1;
            break;
        }else if(a[i] < mid && a[i - 1] < mid){
            l0 = i + 1;
            break;
        }
    }

    for(int i = n - 1 ; i < n * 2 - 2 ; ++i){
        if(a[i] >= mid && a[i + 1] >= mid){
            r1 = i + 1;
            break;
        }else if(a[i] < mid && a[i + 1] < mid){
            r0 = i + 1;
            break;
        }
    }

    return min(abs(n - l1), abs(n - r1)) < min(abs(n - l0), abs(n - r0));
}

int meguru_search(int ok, int ng){
    while(abs(ok - ng) > 1){
        int mid = (ok + ng) / 2;
        if(check(mid)){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    return ok;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;

    a.resize(n * 2 - 1);
    rep(i, n * 2 - 1){
        cin >> a[i];
    }

    int ans = meguru_search(0, n * 2);
    cout << ans << endl;

    return 0;
}
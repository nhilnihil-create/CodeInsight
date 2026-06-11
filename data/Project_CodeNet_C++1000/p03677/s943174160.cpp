#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define REVERSE(a) reverse(a.begin(), a.end())
#define int long long
#define INF 1000000000000000
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int, int> Pii;

template<typename T>
void readvec(vector<T> &a);
void readindex(vector<int> &a);

class BIT
{
public:
    vector<int> bit;
    int M;

    BIT(int M):
        bit(vector<int>(M+1, 0)), M(M) {}

    int sum(int i) {
        if (!i) return 0;
        return bit[i] + sum(i-(i&-i));
    }

    void add(int i, int x) {
        if (i > M) return;
        bit[i] += x;
        add(i+(i&-i), x);
    }
};

void add_b(int l, int r, BIT &b0, BIT &b1, int n){
    b1.add(l, 1);
    b1.add(r + 1, -1);
    b0.add(l, n - l);
    b0.add(r + 1, l - n);
}

signed main(){

    int n, m; cin >> n >> m;
    vec a(n); readvec(a);

    //得する回数を b0.sum(x) + x * b1.sum(x) とする
    BIT b0(m + 1), b1(m + 1);
    int s = 0;

    REP(i, n - 1){
        if(a[i] < a[i + 1]){
            s += a[i + 1] - a[i];
            add_b(a[i] + 1, a[i + 1], b0, b1, 0);
        }
        if(a[i] > a[i + 1]){
            s += (m - a[i]) + 1 + (a[i + 1] - 1);
            add_b(a[i] + 1, m, b0, b1, 0);
            add_b(1, a[i + 1], b0, b1, m - a[i]);
        }
    }

    int ans = 0;
    FOR(i, 1, m + 1){
        ans = max(ans, b0.sum(i) + i * b1.sum(i));
    }

    ans = s - ans;
    cout << ans;
    
    return 0;
}


template<typename T>
void readvec(vector<T> &a){
    REP(i, a.size()){
        cin >> a[i];
    }
}
void readindex(vector<int> &a){
    REP(i, a.size()){
        cin >> a[i];
        a[i]--;
    }
}
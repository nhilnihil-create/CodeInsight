#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define int long long
#define vec(a,n) vector<int> (a)((n));
#define Vec(a,n) vector<string> (a)((n));
#define twovec(a,n,m) vector<vector<int>> a(n,vector<int>(m,0));
#define Twovec(a,n,m) vector<vector<double>> a(n,vector<double>(m,0));
#define P pair<int,int>
#define All(a) (a).begin(),(a).end()
#define Sort(a) sort(All(a));
#define Reverse(a) reverse(All(a));
#define PQ(n) priority_queue<P,vector<P>,greater<P>> (n)
#define pq(n) priority_queue<int> (n)
#define print(a) cout << (a) << endl;
#define printD(a) cout << setprecision(10) << ans << endl;
using namespace std;
int max_int = 1000000007;
void Debug(auto a);
int nibul(auto a,auto b);
int nibuu(auto a,auto b);
void input(vector<int>& a,int n);

int n,m;
struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

signed main(){
    cin >> n;
    if(n==1){
        int x,y;
        cin >> x >> y;
        (x==y)? cout << 1 << endl : print(0)
        return 0;
    }
    vec(a,n);
    vec(b,n);
    vec(c,n);
    vec(d,n);
    int a_max,b_max=-1;
    REP(i,n){
        cin >> a[i];
        if(i==0){
            c[i] = a[i];
            a_max = i;
        }
        else if(a[i] != a[i-1]){
            c[i] = a[i];
            a_max = i;
        }
    }
    REP(i,n){
        cin >> b[i];
        if(b[i] != b[i-1] && i != 0){
            c[i-1] = b[i-1];
            if(b_max == -1){
                b_max = i-1;
            }
        }
    }
    c[n-1] = b[n-1];
    if(a[n-1] != b[0] || a_max > b_max && b_max != -1){
        print(0)
    }
    else{
        int ans = 1;
        REP(i,a_max){
            if(c[i] == 0){
                c[i] = c[i-1];
                d[i]=c[i];
            }
            else{
                d[i]=1;
            }
        }
        for(int i=n-1;i>=a_max;i--){
            if(c[i] == 0){
                c[i] = c[i+1];
                d[i] = c[i];
            }
            else{
                d[i] = 1;
            }
        }
        //Debug(d);
        REP(i,n){
            ans *= d[i];
            ans %= max_int;
        }
        print(ans)
    }

    return 0;
}

void Debug(auto a){
    cout << "{ ";
    for(auto b: a){
        cout << b << " ";
    }
    cout << "}" << endl;
}
int nibul(auto a,auto b){
    int x = lower_bound(All(a),b) - a.begin();
    //key以上の初めてのitr
    return x;
}
int nibuu(auto a,auto b){
    int x = upper_bound(All(a),b) - a.begin();
    //key以下の最後のitr
    return x-1;
}

void input(vector<int>& a,int n){
    REP(i,n){
        cin >> a[i];
    }
}

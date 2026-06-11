#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define rep2(i, s, n) for(int i=s; i<(n); ++i)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;

template<typename T>
using priority_queue_rev = priority_queue<T, vector<T>, greater<T> >;

static const int INTINF = (2147483647 >> 1); // 10^9 + 5000
static const ll LLINF = (9223372036854775807 >> 1);
static const int MAX = 1e5+1;
static const ll MOD = 1e9+7;

namespace Kunitaka{
    template<
        typename TYPE,
        std::size_t SIZE
    >
    std::size_t array_length(const TYPE (&array)[SIZE])
    {
        return SIZE;
    }

    template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
    template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
}
using namespace Kunitaka;
namespace Printer{
    void br(){
        cout << endl;
    }

    void loop_cnt(int i){
        cout << "i = " << i << endl;
    }

    void loop_cnt(int i, int j){
        cout << "i = " << i << ", " << "j = " << j << endl;
    }

    template<class T>
    void print(T x){
        cout << x << endl;
    }

    template<class T, class S>
    void print(T x, S y){
        cout << x << "," << y << endl;
    }

    template<class T, class S, class U>
    void print(T x, S y, U z){
        cout << x << "," << y << "," << z << endl;
    }

    template<class T, class S>
    void print(pair<T, S> p){
        cout << p.first << ", " << p.second << endl;
    }

    template<
        typename TYPE,
        std::size_t SIZE
    >
    void print(const TYPE (&array)[SIZE]){
        int lim = array_length(array);
        for(int i=0; i<lim; i++){
            if(i) cout << " ";
            cout << array[i];
        }
        cout << endl;
    }

    template<class S>
    void print(vector<S> v){
        for(int i=0; i<v.size(); i++){
            if(i) cout << " ";
            cout<< v[i];
        }
        cout << endl;
    }

    template<class S>
    void print(vector<vector<S> > vv){
        for(int i=0; i<vv.size(); i++){
            for(int j=0; j<vv[i].size(); j++){
                if(j) cout << " ";
                cout << vv[i][j];
            }
            cout << endl;
        }
    }

    void yesno(bool x){
        if(x) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
};
using namespace Printer;

struct packet{
    int sports;
    int val;
    int arr[301] = {0};
    bool operator<(const packet &a) const{
        return val > a.val;
    }
};

int main(int argc, const char * argv[]) {
    //提出時、消す----//
    //--------------//


    // input
    cout << fixed << setprecision(10);
    int N, M; cin >> N >> M;
    vector<packet> v(M);
    int vv[N][M];
    rep(i, N){
        rep(j, M){
            cin >> vv[i][j];
            vv[i][j]--;
        }
    }

    rep(k, M){
        int cnt = 0;
        rep(i, N){
            rep(j, M){
                if(vv[i][j] == k){
                    v[k].arr[i] = j;
                    if(!j) cnt++;
                }
            }
        }
        v[k].sports = k;
        v[k].val = cnt;
    }

    int ans = INTINF;
    rep(k, M){
        sort(ALL(v));
        // cout << k << endl;
        // rep(i, v.size()){
        //     rep(j, M){
        //         if(j) cout << " ";
        //         cout << v[i].arr[j];
        //     }
        //     cout << endl;
        // }
        // cout << v[0].sports << " " << v[0].val << endl;
        ans = min(ans, v[0].val);
        rep2(i, 1, v.size()){
            int cnt = 0;
            rep(j, N){
                if(v[i].arr[j] > v[0].arr[j]){
                    v[i].arr[j]--;
                }
                if(v[i].arr[j] == 0) cnt++;
            }
            v[i].val = cnt;
        }
        v.erase(v.begin());
    }

    cout << ans << endl;
    
    
    return 0;
}

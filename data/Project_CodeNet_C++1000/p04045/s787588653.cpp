#include <bits/stdc++.h>
using namespace std;

#define rp(i, k, n) for (int i = k; i < n; i++)
typedef long long ll;
typedef double ld;

template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
const double PI=3.14159265358979323846;


int main() {
    int n, k; cin >> n >> k;
    int dislike = 0;
    rp(i, 0, k){
        int d; cin >> d;
        dislike += (1<<d);
    }
    
    rp(i, n, 100000){
        int c = i;
        int flag = true;
        while(c > 0){
            int m = c%10;
            if(dislike & (1<<m)) flag = false;
            c/=10;
        }
        if(flag) {
            cout << i << endl;
            return 0;
        }
    }
}
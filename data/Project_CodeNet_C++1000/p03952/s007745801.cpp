//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;



int main() {
    int n, x;
    cin >> n >> x;

    

    if(x == 1 || x == 2*n-1) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        if(n == 2) {
            rep(i, 3) {
                cout << i+1 << endl;
            }
            return 0;
        }
        vi vec(2*n-1);
        rep(i, 2*n-1) {
            vec[i] = i+1;
        }
        swap(vec[x-1], vec[n-1]);
        swap(vec[0], vec[n-2]);
        if(vec[n-3] < x) {
            swap(vec[n-3], vec[2*n-2]);
        } 
        if(x>n) swap(vec[n-2], vec[n-3]);
        rep(i, 2*n-1) {
            cout << vec[i] << '\n';
        }
    }
}
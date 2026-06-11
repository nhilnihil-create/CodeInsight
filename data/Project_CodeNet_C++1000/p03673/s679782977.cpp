#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    vector<int> a(N);
    rep(i, N){
        cin >> a[i];
    }

    vector<int> b;
    if(N%2 == 1){
        for (int i = N-1; i >= 0; i-=2){
            b.push_back(a[i]);
        }
        for (int i = 1; i < N; i+=2){
            b.push_back(a[i]);
        }
    } else {
        for (int i = N-1; i >= 0; i-=2){
            b.push_back(a[i]);
        }
        for (int i = 0; i < N; i+=2){
            b.push_back(a[i]);
        }
    }

    int x = b.size();
    rep(i, x){
        cout << b[i];
        if(i != x-1){
            cout << " ";
        } else {
            cout << endl;
        }
    }

    return 0;
}
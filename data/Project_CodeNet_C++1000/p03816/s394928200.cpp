#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    set<int> s;
    rep(i, N){
        int a; cin >> a;
        s.insert(a);
    }

    int ss = s.size();
    int x = N - ss;
    if(x%2 == 1)ss--;

    cout << ss << endl;

    return 0;
}
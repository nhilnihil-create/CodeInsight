#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
int main()
{
    int N ,M;
    
    cin >> N >> M;
    vector<int> a(N), b(N), c(M), d(M);
    
    rep(i, N) cin >> a[i] >> b[i];
    rep(i, M) cin >> c[i] >> d[i];

    rep(i, N){
        int min_value = 1e9;
        int checkpoint_num;
        rep(j, M){
            int dist = abs(a[i]-c[j])+abs(b[i]-d[j]);
            if(min_value > dist) {
                checkpoint_num = j;
                min_value = dist;
            }
        }
        cout << checkpoint_num+1 << endl;
    }


    return 0;
}
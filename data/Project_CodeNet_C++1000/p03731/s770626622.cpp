#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define reps(i,s,n) for (int i = (s); i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    
    int N, T;
    cin >> N >> T;
    int t[N];
    for(int i = 0; i < N; i++){
        cin >> t[i];
    }

    int total = 0;
    for(int i = 1; i <= N; i++){
        if(i == N){
            total += T;
        } else {
            int dt = t[i] - t[i-1];
            if(dt < T){
                total += dt;
            } else {
                total += T;
            }
        }
   }
    cout << total << endl;

    return 0;
}
    
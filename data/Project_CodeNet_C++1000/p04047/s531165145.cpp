#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int N;
    cin >> N;
    vector<int> vec(2 * N);
    rep(i,2 * N){
        cin >> vec[i];
    }
    int ans = 0;
    sort(all(vec));
    for (int i = 0; i < 2 * N; i += 2){
        ans += vec[i];
    }
    cout << ans << endl;
}


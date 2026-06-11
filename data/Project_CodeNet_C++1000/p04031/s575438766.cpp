#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int N;
    cin >> N;
    vector<int> vec(N);
    rep(i,N){
        cin >> vec[i];
    }
    int ans = 10000000;
    for (int i = -100; i <= 100; i++){
        int ans_sub = 0;
        rep(j,N){
            ans_sub += (i - vec[j]) * (i - vec[j]);
        }
        ans = min(ans,ans_sub);
    }
    cout << ans << endl;
}

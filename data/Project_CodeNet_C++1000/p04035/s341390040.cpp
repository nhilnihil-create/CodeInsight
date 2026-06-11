#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, a, b) for(int i = a; i < b; i++)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using P = pair<int,int>;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int main(){
    int n, l;
    cin >> n >> l;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int maxNum = 0, maxI = 0;
    for(int i = 0; i < n-1; i++){
        if (chmax(maxNum, a[i]+a[i+1])) maxI = i;
    }


    vector<int> ans;
    if (maxI == 0){
        if (a[0] + a[1] < l){
            cout << "Impossible" << endl;
            return 0;
        }
        for(int i = 0; i < n-1; i++){
            ans.push_back(i);
        }
    }
    else if (maxI == n-1){
        if (a[n-1] + a[n-2] < l){
            cout << "Impossible" << endl;
            return 0;
        }
        for(int i = n-2; i >= 0; i--){
            ans.push_back(i);
        }
    }else{
        if (a[maxI-1] > a[maxI+1]){
            if (a[maxI-1] + a[maxI] < l){
                cout << "Impossible" << endl;
                return 0;
            }
            for(int i = maxI-1; i >= 0; i--){
                ans.push_back(i);
            }
            for(int i = maxI+1; i < n; i++){
                ans.push_back(i-1);
            }
            
        }else{
            if (a[maxI] + a[maxI+1] < l){
                cout << "Impossible" << endl;
                return 0;
            }
            for(int i = maxI+1; i < n; i++){
                ans.push_back(i-1);
            }
            for(int i = maxI-1; i >= 0; i--){
                ans.push_back(i);
            }
        }
    }
    reverse(all(ans));
    cout << "Possible" << endl;
    rep(i, ans.size()){
        cout << ans[i]+1 << endl;
    }
    return 0;
}
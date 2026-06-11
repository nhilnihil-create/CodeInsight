#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;cin>>n;
    vector<int> a(n);
    rep(i,n){
        cin>>a[i];
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        // おなじ
        while(i+1 < n && a[i]==a[i+1]){
            i++;
        }
        // up
        if(i+1<n && a[i]<a[i+1]){
            while(i+1 < n && a[i]<=a[i+1]){
                // iをすすめる
                i++;
            }
        }
        // down
        else if(i+1<n && a[i] > a[i+1]){
            while(i+1 < n && a[i]>=a[i+1]){
                i++;
            }
        }
        // 分割
        ans+=1;
    }
    cout<<ans<<endl;
}
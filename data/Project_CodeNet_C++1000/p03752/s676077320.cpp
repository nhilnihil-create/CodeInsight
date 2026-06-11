#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
typedef pair<int,int> P;
struct edge{int to, id;};
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mod 1000000007

int main(){
    int n,k;
    cin >> n >> k;
    ll a[n];
    rep(i,n){
        ll temp;
        cin >> temp;
        a[i] = temp;
    }
    ll ans = 3000000000000;
    for (int bit = 0; bit < (1<<n); ++bit) {
        vector<int> S;
        //bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (bit & (1<<i)) { // 列挙に i が含まれるか
                S.push_back(i);
            }
        }
      if(k == 1){
        cout << 0 << endl;
        return 0;
      }
      else if(S.size() == k){
        ll least=0;
        ll temp = 0;
        int count = 0;
        int index = S[count];
        rep(i,n){
          if(i - index == 0){
            //cout << count << endl;
              //temp += max(0,least - a[index]);
            if(least+1 >= a[index]){
              temp = temp + least +1- a[index];
            }
              count++;
              index = S[count];
            least = max(least+1,a[i]);
          }
          else least = max(least,a[i]);
          //if(a[i] > least+1) least = a[i];
          if(count == k) break;
        }
        ans = min(ans,temp);
      }
    }
    cout << ans << endl;
}
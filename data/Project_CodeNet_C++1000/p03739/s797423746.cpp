    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;

    void solve() {
        ll n;
        cin >> n;
        ll a[n];
        for(ll i = 0; i < n; i++) cin >> a[i];
        ll sum = 0, cnt = 0, sum1=0,cnt1=0;
        for(ll i = 0; i < n; i++){
            sum+=a[i];
            if(i%2 == 0){
                if(sum > 0) continue;
                else cnt += (1-sum), sum = 1;
            } else {
                if(sum < 0) continue;
                else cnt += (sum+1), sum = -1;
            }
        }
        for(ll i = 0; i < n; i++){
            sum1+=a[i];
            if(i%2 == 1){
                if(sum1 > 0) continue;
                else cnt1 += (1-sum1), sum1 = 1;
            } else {
                if(sum1 < 0) continue;
                else cnt1 += (sum1+1), sum1 = -1;
            }
        }
        cout << min(cnt1, cnt) << endl;
    }

    int main() {
      cin.sync_with_stdio(0); cin.tie(0);
      cin.exceptions(cin.failbit);
      //ll ti;   cin >> ti;  while(ti--)
      solve();
      return 0;
    }

#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200005

int main() {
    int n,m;
    cin >> n >> m;
    int a[n];
    vector<int> l;
    vector<pair<int,int>> r;
    ll ans = 0;
    rep(i,n){
        cin >> a[i];
        if(0<i){
            if(a[i-1] < a[i]){
                ans += a[i] - a[i-1];
                l.push_back(a[i-1]);
                r.push_back(P(a[i],a[i-1]));
            }else{
                ans += a[i] + m - a[i-1];
                l.push_back(a[i-1]);
                r.push_back(P(a[i]+m,a[i-1]));
            }
        }
    }

    if(m<=2){
        cout << ans << endl;
        return 0;
    }
    if(n==2){
        cout << '1' << endl;
        return 0;
    }

    sort(l.begin(),l.end());
    sort(r.begin(),r.end());

    ll dp[m * 2 + 100] = {};

    ll count = 0;
    ll count1 = 0;
    ll count2 = 0;
    ll sum = 0;
    ll l_ = 0;
    ll r_ = 0;
    srep(i,1,m*2){
        if(i==1){
            while(l[l_]==1){
                count1++;
                l_++;
            }
        }else if(i==2){
            count2 = count1;
            count1 = 0;
            while(l_<n-1 && l[l_]==2){
                count1++;
                l_++;
            }
            while(r_<n-1 && r[r_].first==i){
                count2--;
                r_++;
            }
        }else{
            count += count2;
            count2 = count1;
            count1 = 0;
            sum += count;
            dp[i] = sum;
            while(l_<n-1 && l[l_]==i){
                count1++;
                l_++;
            }
            while(r_<n-1 && r[r_].first==i){
                if(r[r_].second == i-1){
                    count2--;
                }else{
                    count--;
                    sum -= (i-r[r_].second-1);
                }
                r_++;
            }
        }
    }

    ll ans2 = ans;
    srep(i,1,m+1){
        ans2 = min(ans2, ans-dp[i]-dp[i+m]);
    }

    cout << ans2 << endl;
    return 0;
}
 
 

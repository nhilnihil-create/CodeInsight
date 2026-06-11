#include <bits/stdc++.h>
#define pb push_back
#define S second
#define F first

using namespace std;
typedef long long ll;
#define int ll
typedef pair<int,int> pii;
const int maxn = 5e5 + 10;
int ans[maxn];
int32_t main(){
    int n,a;
    vector<pii> v;
    cin >> n;
    for (int i =0;i < n;i++){
        cin >> a;
        v.pb({a,i + 1});
    }
    sort(v.rbegin(),v.rend());
    int l = n + 1,sum = 0,lindex= 0;
    for (int i = 0;i < n;i++){
        int num = v[i].F,index = v[i].S;
      //   cout << num << ' ' << sum << ' ' << i  << ' ' <<   lindex << endl;
        if (index < l){
            ans[l] = sum - (num * i);
            sum = num * i;
            lindex = i;
            l = index;
        }
        sum += num;

    }
    ans[l] = sum;
    for (int i = 1;i <= n;i++) cout << ans[i] << endl;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define LLINF 9223372036854775807
#define MOD ll(1e9+7)

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a;
    for(int i = 0; i < n; i++){
        int ta;
        cin >> ta;
        if(ta <= k){
            a.push_back(ta);
        }
    }
    sort(a.begin(),a.end());
    n = a.size();

    int ok = -1;
    int ng = n;

    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;

        vector<vector<bool>> dp2(n,vector<bool>(k+1,0));
        dp2[0][0] = true;
        for(int i = 0; i < n-1; i++){
            int index = i >= mid ? i+1 : i;
            for(int j = 0; j <= k; j++){
                if(dp2[i][j]){
                    dp2[i+1][min(j+a[index],k)] = true;
                    dp2[i+1][j] = true;;
                }

            }
        }
        bool is_wasteful = true;
        for(int i = k-a[mid]; i < k; i++){
            if(dp2[n-1][i]){
                is_wasteful = false;
            }
        }
        if (is_wasteful) ok = mid;
        else ng = mid;
    }


    cout << ok + 1 << endl;

    return 0;

}

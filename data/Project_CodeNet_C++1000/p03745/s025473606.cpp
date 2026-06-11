#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()
#define endl "\n"

using ll = long long;
using P = pair<int,int>;
using mp =  map<char,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);

    rep(i, n){
        cin >> v[i];
    }

    int ans = 0;
    rep(i, n){
        int j1 = i, j2 = i;
        if(v[i] <= v[i+1]){
            for(j1 = i; j1 < n-1; j1++){
                if(v[j1] > v[j1+1]){
                    break;
                }
            }
        }

        if(v[i] >= v[i+1]){
            for(j2 = i; j2 < n-1; j2++){
                if(v[j2] < v[j2+1]){
                    break;
                }
            }
        }

        i = max(j1, j2);
        ans++;
    }

    cout << ans << endl;


    return 0;
}
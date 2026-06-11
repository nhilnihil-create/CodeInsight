#include <bits/stdc++.h>
using namespace std;

using P = pair<int,int>;
using P3 = pair<P, int>;
using ll = long long int;
constexpr int INF = 1<<30;
constexpr ll MOD = (1e9)+7;


int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int> > a(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
            a[i][j]--;
        }
    }
    int ans = n;
    vector<int> cnt(m), idx(n);
    vector<bool> used(m);
    for(int i=0;i<n;i++){
        cnt[a[i][0]]++;
    }
    for(int i=0;i<m-1;i++){
        int cmax = 0, id = -1;
        for(int j=0;j<m;j++){
            if(cnt[j] > cmax){
                cmax = cnt[j];
                id = j;
            }
        }
        ans = min(ans, cmax);
        used[id] = true;
        fill(cnt.begin(), cnt.end(), 0);
        for(int j=0;j<n;j++){
            while(idx[j]<m && used[a[j][idx[j]]]) idx[j]++;
            cnt[a[j][idx[j]]]++;
        }
    }
    cout << ans << endl;
    return 0;
}

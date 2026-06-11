#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n,vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }
    int ans = n;
    while(!a[0].empty()){
        int cnt[m+1];
        fill(cnt,cnt+m+1,0);
        for(int i=0; i<n; i++){
            cnt[a[i][0]]++;
        }
        int b=0,c=0;
        for(int i=0; i<m+1; i++){
            if(c < cnt[i]){
                b = i;
                c = cnt[i];
            }
        }
        ans = min(ans,c);
        for(int i=0; i<n; i++){
            auto p = find(a[i].begin(),a[i].end(),b);
            a[i].erase(p);
        }
    }
    cout << ans << endl;
    return 0;
}

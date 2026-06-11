#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    vector<pair<int,int>> num(m, {0,0});
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
            a[i][j] -= 1;

            if(j == 0){
                num[a[i][j]].first += 1;
                num[a[i][j]].second = a[i][j];
            }
        }
    }
    sort(num.begin(), num.end());
    reverse(num.begin(), num.end());

    int ans = num[0].first;
    vector<bool> removed(m, false);
    for(int x=0; x<m-1; x++){
        removed[num[0].second] = true;
        num.assign(m,{0,0});

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(removed[a[i][j]] == false){
                    num[a[i][j]].first += 1;
                    num[a[i][j]].second = a[i][j];
                    break;
                }
            }
        }

        //for(int j=0; j<m; j++) cout << num[j].first << " ";
        //cout << endl;

        sort(num.begin(), num.end());
        reverse(num.begin(), num.end());
        ans = min(ans, num[0].first);
    }
    cout << ans << endl;
    return 0;
}
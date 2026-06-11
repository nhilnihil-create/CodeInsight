#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef pair<int, int> PA;
typedef map<PA, int> MA;


MA mp;
int a, b, h, w, n;
int dx[] = {0, 1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};

signed main()
{
    cin >> h >> w >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        for(int j = 0; j < 9; j++){
            mp[PA(a + dx[j], b + dy[j])]++;
            //printf("%d %d %d\n", a + dx[j], b + dy[j], mp[PA(a + dx[j], b + dy[j])]);
        }
    }
    MA :: iterator ite;
    int sum = 0;
    for(ite = mp.begin(); ite != mp.end(); ite++){
        if(1 < ite -> first.first && ite -> first.first < h && 1 < ite -> first.second && ite -> first.second < w)
            if(ite -> second > 0){
                sum++;
        }
    }
    cout << (h - 2) * (w - 2) - sum << endl;

    for(int j = 1; j < 10; j++){
        int ans = 0;
        for(ite = mp.begin(); ite != mp.end(); ite++){
            if(1 < ite -> first.first && ite -> first.first < h && 1 < ite -> first.second && ite -> first.second < w)
            if(ite -> second == j){
                ans++;
            }
        }
        cout << ans << endl;
    }


    return 0;
}

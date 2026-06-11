#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;

int ans[105][105];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int r, c, n;
    cin >> r >> c >> n;
    map<int, int> freq;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        freq[i + 1] = x;
    }
    int cnt = 1;
    for(int i = 0; i < r; i++){
        if(i % 2 == 0){
            for(int j = 0; j < c; j++){
                ans[i][j] = cnt;
                freq[cnt]--;
                if(freq[cnt] == 0) cnt++;
            }
        }
        else{
            for(int j = c - 1; j >= 0; j--){
                ans[i][j] = cnt;
                freq[cnt]--;
                if(freq[cnt] == 0) cnt++;
            }
       }
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }



    return 0;
}

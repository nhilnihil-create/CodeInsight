#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

static const int MAX = 100;
int row[MAX], col[MAX];

int main(){
    int w, h, n, x, y, a;
    cin >> w >> h >> n;
    for(int i = 0; i < max(w, h); i++){
        row[i] = col[i] = 0;
    }
    for(int k = 0; k < n; k++){
        cin >> x >> y >> a;
        switch(a){
            case 1:
            for(int j = 0; j < x; j++){
                col[j]++;
            }
            break;
            case 2:
            for(int j = x; j < w; j++){
                col[j]++;
            }
            break;
            case 3:
            for(int i = h-y; i < h; i++){
                row[i]++;
            }
            break;
            case 4:
            for(int i = 0; i < h-y; i++){
                row[i]++;
            }
            break;
        }
    }
    int cnt = 0;
    int ans = h * w;
    for(int i = 0; i < h; i++){
        if(row[i]){
            ans -= w;
            cnt++;
        }
    }
    for(int j = 0; j < w; j++){
        if(col[j]){
            ans -= h-cnt;
        }
    }
    cout << ans << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pi;

int n;
const int maxn = 105;
int cnt[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    int mx = 0;
    for(int i = 1;i <= n;i++){
        int a;
        cin >> a;
        cnt[a]++;
        mx = max(mx, a);
    } 
    int lb = (mx + 1) / 2;
    for(int i = 1;i < lb;i++){
        if(cnt[i] != 0){
            cout << "Impossible" << endl;
            return 0;
        }
    }
    if(lb * 2 == mx){
        if(cnt[lb] != 1){
            cout << "Impossible" << endl;
            return 0;
        }
    }else{
        if(cnt[lb] != 2){
            cout << "Impossible" << endl;
            return 0;
        }
    }
    for(int i = lb + 1;i <= mx;i++){
        if(cnt[i] < 2){
            cout << "Impossible" << endl;
            return 0;
        }
    }
    cout << "Possible" << endl;
    return 0;
}

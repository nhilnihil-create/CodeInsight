#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pi;

const int maxn = 1e5 + 5;

ll a[maxn];
int n;
ll L;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> L;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    int pos = -1;
    for(int i = 1;i < n;i++){
        if(a[i] + a[i + 1] >= L){
            pos = i;
            break;
        }
    }
    if(pos == -1){
        cout << "Impossible" << endl;
    }else{
        cout << "Possible" << endl;
        for(int j = 1;j < pos;j++){
            cout << j << endl;
        }
        for(int j = n - 1;j > pos;j--){
            cout << j << endl;
        }
        cout << pos << endl;
    }
    return 0;
}

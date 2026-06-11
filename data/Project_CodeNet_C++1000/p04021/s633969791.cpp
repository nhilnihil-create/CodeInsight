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

int n;
int a[maxn];
int id[maxn];

bool cmp(int i, int j){
    return a[i] < a[j];
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        id[i] = i;
    }
    sort(id + 1, id + 1 + n, cmp); 
    int ans = 0;
    for(int i = 1;i <= n;i++){
        if((id[i] - i) % 2){
            ans++;
        }
    }
    cout << ans / 2 << endl;
    return 0;
}

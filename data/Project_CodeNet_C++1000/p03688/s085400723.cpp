#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;
int cnt[N];

void NO(){
    cout << "No\n";
    exit(0);
}

int main(){
    fastIO;
    int n;
    cin >> n;
    int mn = n, mx = 0;
    int a;
    for(int i = 1; i <= n; i ++ ){
        cin >> a;
        cnt[a] ++ ;
        mn = min(mn, a);
        mx = max(mx, a);
    }
    if(mx - mn > 1){
        NO();
    }
    if(mx - mn == 1){
        if(mx > cnt[mn] && mx <= cnt[mn]+cnt[mx]/2)
            cout << "Yes\n";
        else
            NO();
    }
    else{
        if(mx * 2 <= n || mx == n-1){
            cout << "Yes\n";
        }
        else{
            NO();
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

const int N = 101;

int n, cnt[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int mn = n, mx = 0;
    for(int i = 0 ; i < n ; i++){
        int x;
        cin >> x;
        cnt[x]++;
        mn = min(mn, x);
        mx = max(mx, x);
    }
    if(mn != (mx + 1) / 2) finish("Impossible");
    if(mx % 2 == 0 && cnt[mn] != 1) finish("Impossible");
    if(mx % 2 && cnt[mn] != 2) finish("Impossible");
    for(int i = mn ; i <= mx ; i++){
        if(cnt[i] == 0) finish("Impossible");
    }
    cout << "Possible" << endl;
}

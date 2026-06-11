#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int n, x;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    if(x == 1 || x == 2 * n - 1) finish("No");
    vector <int> a(2 * n - 1);
    a[n - 1] = x;
    a[n] = x + 1;
    a[n - 2] = x - 1;
    if(x + 2 <= 2 * n - 1) a[n - 3] = x + 2;
    else a[n + 1] = x - 2;
    set <int> all;
    for(int i = 1 ; i <= 2 * n - 1 ; i++){
        all.insert(i);
    }
    for(auto &i : a){
        if(i) all.erase(i);
    }
    for(auto &i : a){
        if(i == 0){
            i = *all.begin();
            all.erase(all.begin());
        }
    }
    cout << "Yes\n";
    for(auto &i : a) cout << i << "\n";
}

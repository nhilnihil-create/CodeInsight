#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int n;
vector <int> a;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    for(auto &i : a) cin >> i;
    sort(a.rbegin(), a.rend());
    if(a[0] - a.back() > 1) finish("No");
    if(a[0] == a.back() + 1){
        int x = 0;
        while(a.back() != a[0]){
            x++;
            a.pop_back();
        }
        for(auto &i : a) i -= x;
    }
    else if(a[0] == n - 1) finish("Yes");
    n = a.size();
    if(a[0] > 0 && 2 * a[0] <= n) cout << "Yes" << endl;
    else cout << "No" << endl;
}

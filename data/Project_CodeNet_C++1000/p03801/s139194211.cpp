#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    ll a[100002];
    ll copy[100002];
    vector<int> v;
    ll lar = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        copy[i] = a[i];
        if(a[i] > lar){
            lar = a[i];
            v.push_back(i);
        }
    }
    sort(copy, copy + n);
    ll ans[100002] {0};
    int now = 0;
    for(int i = 0; i < n; i++){
        if(copy[i] <= a[v[now]]){
            if(now == 0) ans[v[now]] += copy[i];
            else ans[v[now]] += copy[i] - a[v[now - 1]];
        }
        else{
            if(now == 0) ans[v[now]] += (n - i) * a[v[now]];
            else ans[v[now]] += (n - i) * (a[v[now]] - a[v[now - 1]]);
            now++;
            i--;
        }
    }
    for(int i = 0; i < n; i++) cout << ans[i] << endl;
}
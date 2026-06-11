#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using p = pair<int, int>;

int main(){
    ll n, k;
    cin >> n >> k;
    vector<p> array;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        array.push_back(p(a, b));
    }
    sort(array.begin(), array.end());
    ll ans = 0, sum = 0;
    while(sum < k){
        sum += array[ans].second;
        ans++;
    }
    cout << array[ans - 1].first << endl;
}

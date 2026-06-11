#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    int n;
    cin >> n;
    ll tmp;
    vector<ll> a;
    for (int i=0; i<n; i++){
        cin >> tmp;
        auto it = find(a.begin(), a.end(), tmp);
        if (it == a.end()){
            a.emplace_back(tmp);
        } else{
            a.erase(a.begin()+distance(a.begin(), it));
        }
    }
    cout << a.size() << endl;
    return 0;
}
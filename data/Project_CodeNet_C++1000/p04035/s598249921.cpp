#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int n, L;
vector <int> a;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> L;
    a.resize(n);
    ll sum = 0;
    for(auto &i : a){
        cin >> i;
        sum += i;
    }
    int idx = -1;
    for(int i = 0 ; i + 1 < n ; i++){
        if(a[i] + a[i + 1] >= L) idx = i;
    }
    if(idx == -1) finish("Impossible");
    cout << "Possible" << endl;
    idx++;
    for(int i = 1 ; i < idx ; i++){
        cout << i << "\n";
    }
    for(int i = n - 1 ; i > idx ; i--){
        cout << i << "\n";
    }
    cout << idx << endl;
}

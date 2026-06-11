#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main(){
    ll k;
    cin >> k;
    if(k==0){
        cout << 2 << endl;
        cout << "1 1" << endl;
        return 0;
    }
    int n = 50;
    ll x = k/50;
    ll r = k%50;

    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        a[i] = i+x;
    }

    for(int i = 0; i < r; i++){
        vector<ll>::iterator min = min_element(a.begin(), a.end());
        size_t minIndex = distance(a.begin(), min);
        for(int j = 0; j < n; j++){
            if(j==minIndex){
                a[j] += n;
            }else{
                a[j] -= 1;
            }
        }
    }
    cout << n << endl;
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;

}

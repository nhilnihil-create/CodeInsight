#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;

    ll a[n], b[n];
    ll max = -1;
    ll k = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];

        if(a[i] > max){
            max = a[i];
            k = b[i];
        }
    }

    cout << max + k << endl;
}
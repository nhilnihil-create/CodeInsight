#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<map>
typedef long long ll; 
using namespace std;
/*
time:
wa:
反省:
考察・解説:
*/
int main() {
    vector<ll>a(3);
    cin >> a[0] >> a[1] >> a[2];
    sort(a.begin(), a.end());

    for(int i = 0; i < 3; i++){
        if(a[i] % 2 == 0){
            cout << '0' << endl;
            return 0;
        }
    }
    ll s = a[0]*a[1];
    cout << s << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<long long int> a(3);
    for(int i=0; i<3; i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());

    if(a[0] % 2 == 0
    || a[1] % 2 == 0
    || a[2] % 2 == 0) cout << 0 << endl;
    else{
        cout << a[0] * a[1] << endl;
    }
    return 0;
}
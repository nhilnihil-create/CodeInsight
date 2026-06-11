#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> r(n);
    vector<int> l(n);
    int res = 0;
    for(int i=0; i<n; i++){
        cin >> l[i] >> r[i];
        res = res + (r[i] - l[i] + 1);
    }
    cout << res << endl;
    return 0;
}



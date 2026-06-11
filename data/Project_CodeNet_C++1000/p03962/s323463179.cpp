#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> n(3);
    for(int i=0; i<3; i++) cin >> n.at(i);
    sort(n.begin(), n.end());
    int ans = 1;
    if(n[0] != n[1] && n[1] != n[2] ) ans = 3;
    else if(n[0] != n[1] && n[1] == n[2] ||
            n[0] == n[1] && n[1] != n[2] ) ans = 2;
    else ans = 1;

    cout << ans << endl;
         
}
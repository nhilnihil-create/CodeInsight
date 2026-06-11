#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,c;
    map<int,int>helper;
    cin >> a >> b >> c;
    helper[a]++;
    helper[b]++;
    helper[c]++;
    helper[5]==2&&helper[7]==1?cout << "YES" <<endl:cout << "NO" << endl;

    return 0;
}

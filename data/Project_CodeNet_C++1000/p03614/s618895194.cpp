#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> p(n);
    vector<bool> same(n,false);
    for(int i = 0; i < n; i++){
        cin >> p[i];
        if(i+1 == p[i]){same[i] = true;}
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(same[i]){ans++;i++;}
    }
    cout << ans << endl;
}

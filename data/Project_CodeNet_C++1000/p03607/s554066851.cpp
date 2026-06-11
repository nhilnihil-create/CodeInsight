#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    vector<int> v;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        v.push_back(n);
    }
    sort(v.begin(), v.end());

    for(unsigned int i=1; i<v.size(); i++){
        if(v[i] == v[i-1]){
            v[i] = 0;
            v[i-1] = 0;
        }
    }

    int ans = 0;
    for(unsigned int i=0; i<v.size(); i++){
        if(v[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}

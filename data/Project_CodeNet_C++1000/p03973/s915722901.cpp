#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

int main(){
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;++i){
        int a;
        cin >> a;
        v.push_back(a);
    }
    i64 ans = v[0] - 1;
    int mini = 2;
    for(int i=1;i<n;++i){
        if(v[i] == mini){
            mini++;
            continue;
        }
        ans += (v[i]+(mini-1))/mini - 1;
    }

    cout << ans << endl;

    return 0;
}
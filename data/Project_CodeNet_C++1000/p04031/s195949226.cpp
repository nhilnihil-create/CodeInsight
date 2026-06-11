#include <bits/stdc++.h>
#define mod 1000000007;

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> v(N);

    for(auto &i : v)
        cin >> i;

    double y = accumulate(v.begin(),v.end(),0.0) / v.size();
    y = round(y);
    int res = 0;
    for(int i = 0 ; i < N; i++)
    {
       res += (v[i]-y) * (v[i]-y);
    }

    cout << res;
}


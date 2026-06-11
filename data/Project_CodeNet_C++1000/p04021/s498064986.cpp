#include <bits/stdc++.h>

using namespace std;
using ll = long long;

long double pi = 3.14159265359;

int main()
{
    int N;cin >> N;
    vector<int> v;
    map<int, int> mp;
    for(int i = 0;i < N;i++){
        int b;cin >> b;
        v.push_back(b);
        mp[b] = i;
    }
    int cnt = 0;
    for(auto a : mp){
        v[a.second] = cnt;
        cnt++;
    }
    int ans = 0;
    //for(int i = 0;i < v.size();i++)cout<<v[i]<<endl;
    for(int i = 0;i < N;i++){
        if((v.at(i) % 2) != (i % 2))ans++;
     }
    cout<<ans/2<<endl;
}

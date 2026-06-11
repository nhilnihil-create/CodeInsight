#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> v1, v2, v3, v4;
bool comp(const pair<int, int> &v1, const pair<int, int> &v2) {
    return v1.first < v2.first;
}
int main(){
    int n, ma, mb; cin >> n >> ma >> mb;
    if (n == 1)v3.push_back(make_pair(0, 0));
    for (int i = 0; i < n/2; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        v1.push_back(make_pair(b*ma-a*mb, c));
    }
    for (int i = n/2; i < n; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        v2.push_back(make_pair(a*mb-b*ma, c));
    }
    for (int i = 0; i < (1<<(n/2)); i++)
    {
        int x = 0, y = 0;
        for (int j = i, k = 0; j > 0; j>>=1,k++){
            if(j & 1) {x += v1[k].first; y += v1[k].second;}
        }
        v3.push_back(make_pair(x, y));
    }
    for (int i = 0; i < 1<<(n-n/2); i++)
    {
        int x = 0, y = 0;
        for (int j = i, k = 0; j > 0; j>>=1,k++){
            if(j & 1) {x += v2[k].first; y += v2[k].second;}
        }
        v4.push_back(make_pair(x, y));
    }
    sort(v4.begin(), v4.end());
    int ans = 1000000000;
    for (int i = 0; i < v3.size(); i++)
    {
        vector<pair<int, int>>::iterator itr = lower_bound(v4.begin(), v4.end(), v3[i], comp);
        if ((*itr).second + v3[i].second == 0) itr++;
        if (itr == v4.end())continue;
        if ((*itr).first == v3[i].first){
            ans = min(ans, (*itr).second + v3[i].second);
        }
    }
    if (ans == 1000000000) cout << -1 << endl;
    else {
        cout << ans << endl;
    }
    
}
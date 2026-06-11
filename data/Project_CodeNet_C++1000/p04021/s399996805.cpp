#include<bits/stdc++.h>

using namespace std;
using ll = long long;

template<class T>
int compress(vector<T>& ar) {
    map<T,int> Map;
    int cur = 0;
    for(auto i : ar)Map[i] = -1;
    for(auto &i:Map)i.second = cur++;
    for(auto &i: ar)i = Map[i];
    return cur;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];
    compress(a);
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] % 2 != i % 2)cnt++;
    }
    if(cnt % 2 == 1) {
        return 1;
    }
    cout << cnt / 2 << endl;
}
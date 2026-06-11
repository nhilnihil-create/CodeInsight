#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> as(n);
    for(int i=0; i<n; i++) cin >> as.at(i);

    vector<int> bs;
    for(int i=n-1; i>=0; i-=2) bs.push_back(as.at(i));

    if(n%2) for(int i=1; i<n; i+=2) bs.push_back(as.at(i));
    else for(int i=0; i<n; i+=2) bs.push_back(as.at(i));

    for(int i=0; i<n; i++)
    {
        if(i!=n-1) cout << bs.at(i) << ' ';
        else cout << bs.at(i) << '\n';
    }

    return 0;
}

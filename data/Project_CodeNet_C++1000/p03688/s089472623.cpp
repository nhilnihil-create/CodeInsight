#include <bits/stdc++.h>
using namespace std;


bool func(vector<int>& v)
{


    int mx = *max_element(v.begin(),v.end());
    int mn = *min_element(v.begin(),v.end());
    int n;

    if(mx==v.size()-1 && mx==mn) return true;
    else n = mx;

    int u=0;
    for(auto x:v) if(x==n-1) u++;

    if(u>=n) return false;
    else if((n-u)*2+u<=v.size()) return true;
    return false;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<int> v(N);
    for(int i=0;i<N;i++) cin >> v[i];
    bool flag = func(v);

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
//
//    vector<int> v = {3,3,3,3,3};
//    cout << func(v,0) << endl;

    return 0;
}

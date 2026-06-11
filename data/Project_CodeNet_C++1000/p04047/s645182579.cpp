#include<bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out2.txt", "w", stdout);
    int T;
    cin >> T;
    vector<int> pp;
    for (int i = 1; i <= 2*T; ++i)
    {
        int x;
        cin>>x;
        pp.push_back(x);
    }
    
    sort(pp.begin(), pp.end());
    
    int sum = 0;
    for (int i = 0; i < pp.size(); i+=2)
    {
        sum += pp[i];
    }
    cout<<sum;
    
    return 0;
}


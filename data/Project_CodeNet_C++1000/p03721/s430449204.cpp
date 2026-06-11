#define MOD 1000000007;
#define input ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll long long

#include <bits/stdc++.h>

using namespace std;
const int N = 2e1 + 5;

int main() {

    ll  n,k;
    cin>>n>>k;
    vector<pair<int,int>> vec;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        vec.push_back({a,b});
    }
    sort(vec.begin(),vec.end());


    int ans;
    for(int i=0;i<n;i++)
    {
        if(vec[i].second>=k)
        {ans=vec[i].first;
            break;}
        else
            k-=vec[i].second;

    }
    cout<<ans;

}
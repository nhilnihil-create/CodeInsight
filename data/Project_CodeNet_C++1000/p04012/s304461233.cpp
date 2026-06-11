#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pii pair<int,int>
#define pll pair<lli,lli>
#define vi  vector<int>
#define vii vector<pair<int,int>>
#define vll vector<lli>
#define pb  push_back
#define mp  make_pair
#define ss  second
#define ff  first
#define all(x) sort(x.begin(),x.end())
map<int,int>m;
void solve()
{
    string a;cin>>a;
    int n=a.size();
    for(int i=0;i<n;i++)
    {
        m[a[i]]++;
    }
    for(pii i:m)
    {
        if(i.ss%2!=0)
        {
            cout<<"No\n";return;
        }
    }
    cout<<"Yes\n";

}

int main()
{
    solve();
}

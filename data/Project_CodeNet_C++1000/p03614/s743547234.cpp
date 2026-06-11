#define MOD 1000000007;
#define input ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll long long

#include <bits/stdc++.h>

using namespace std;
const int N = 2e1 + 5;

int main() {

    ll  n;
    cin>>n;
  vector<int> vec(n+1);
    for(int i=1;i<=n;i++)
    {
   cin>>vec[i];

    }
    ll ans=0;
    for(int i=1;i<=n;i++)
        if(vec[i]==i)
        {
            if(vec[i+1]==i+1&&i+1<=n)
                ans++,i++;
            else
                ans++;
        }

cout<<ans;



}
#include<bits/stdc++.h>
#define endl "\n" 
using namespace std;
#define debug(x) cout<<"The value of "<<#x<<" is "<<x<<endl;
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    cin.sync_with_stdio(0); cin.tie(0); 
    int n,l;
    cin>>n>>l;
    vector<string>vec(n);
    for(auto& i:vec)
    cin>>i;
    sort(vec.begin(),vec.end());
    for(auto i:vec)
    cout<<i;
    cout<<endl;
}

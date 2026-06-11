#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
vector<ll> v;
ll a,b,c;
cin>>a>>b>>c;
v.push_back(a);
v.push_back(b);
v.push_back(c);
if(a%2==0||b%2==0||c%2==0)
{
    cout<<0;
}
else
{
    sort(v.begin(),v.end());
    cout<<v[0]*v[1];
}


}
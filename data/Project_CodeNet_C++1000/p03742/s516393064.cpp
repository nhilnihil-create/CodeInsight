#include<bits/stdc++.h>
//cervello|Phoenix
using namespace std;
#define ll long long int
#define eb emplace_back
#define mk make_pair
#define pr pair<int,int>
#define all(x) x.begin(),x.end()
#define mod 1000000007

int main(){
  ios_base::sync_with_stdio(false);
    // #ifndef ONLINE_JUDGE
    //   freopen("input.txt", "r", stdin);
    //   freopen("output.txt", "w", stdout);
    // #endif
  ll x,y; cin>>x>>y;
  if(abs(x-y)>1)
    cout<<"Alice\n";
  else
    cout<<"Brown\n";
  return 0;
}
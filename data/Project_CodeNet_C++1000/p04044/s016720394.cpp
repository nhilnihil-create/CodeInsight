#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
   int n,l;
   cin>>n>>l;
   vector<string> vec;
   for(int i=0;i<n;i++){
       string x;
       cin>>x;
       vec.push_back(x);
   }
   sort(vec.begin(),vec.end());
   for(auto i:vec){
       cout<<i;
   }
   
}
int main(){
   int t=1;
//   cin>>t;
   while(t--){
       solve();
   }
   return 0;
}
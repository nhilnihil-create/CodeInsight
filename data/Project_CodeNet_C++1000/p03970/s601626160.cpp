#include "bits/stdc++.h"
#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define MOD 1000000007
using namespace std;




int main(){
string n;
string j="CODEFESTIVAL2016";
ll ans=0;
cin>>n;
for(ll i=0;i<n.size();i++){
  if(n[i]!=j[i])
  ans++;
}
cout<<ans<<endl;

}

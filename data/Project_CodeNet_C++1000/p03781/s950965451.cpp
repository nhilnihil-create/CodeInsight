#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const ll mod=1000000007;
int main() {
ll n;
cin>>n;
ll aa=0;
ll counter=0;
for(ll i=1; i>0; i++){
aa+=i;
counter++;
if(aa==n){
cout<<counter<<endl;
break;}
else if(aa>n){
cout<<counter<<endl;
break;}}}


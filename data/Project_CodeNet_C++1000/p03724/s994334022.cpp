#include<bits/stdc++.h>
using namespace std;
int main(){
int n,m;
cin >> n >>m;
map<int,int> mp;
for(int i=0; i<m; i++){
int l,r;
cin >> l >> r;
mp[l]++;
mp[r]++;
}
for(auto e:mp)if(e.second%2!=0){
cout << "NO";
return 0;
}
cout<<"YES";
}
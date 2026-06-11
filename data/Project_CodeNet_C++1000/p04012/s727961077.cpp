#include<bits/stdc++.h>
using namespace std;
int main(){
string w;
cin>>w;
map<char , int > mp;

for(int i=0 ; i<w.size() ; i++){
   char x = w[i];
   mp[x]++;
}
bool flag = 1;
for(auto v : mp){
    if(v.second % 2 == 1) flag = 0;
}

if(flag) cout<<"Yes"<<endl;
else cout<<"No"<<endl;

}

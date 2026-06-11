#include<bits/stdc++.h>
using namespace std;
vector<string>v;
int main(){
 string s;
 int n ,  m ;
 cin >> n >> m ;
 for(int i=1;i<=n;i++){
    cin >> s ;
    v.push_back(s);
 }
 sort(v.begin(),v.end());
 for(int i=0;i<v.size();i++){
    cout << v[i];
 }
 cout << endl;
 return 0;
}


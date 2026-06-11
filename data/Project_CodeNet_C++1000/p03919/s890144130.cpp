#include <bits/stdc++.h> 

using namespace std; 

int main(){
  string s="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  bool x=false;
  int h,w;
  cin>>h>>w;
  vector<vector<string>> data(h, vector<string>(w)); 

for (int i = 0; i < h; i++) { 

for (int j = 0; j < w; j++) { 

cin >> data.at(i).at(j); 
  if(data.at(i).at(j)=="snuke"){
    cout<<s[j]<<i+1;
    x=true;
    break;
  }
  if (x==true){
    break;
  }
}
}
}
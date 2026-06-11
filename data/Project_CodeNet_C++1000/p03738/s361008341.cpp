#include<bits/stdc++.h>
using namespace std;

string comp(string a,string b){
  if(a.size()>b.size()){
    return "GREATER";
  }else if(a.size()<b.size()){
    return "LESS";
  }else{
    for(int i=0;i<a.size();i++){
      if(a.at(i)>b.at(i))
        return "GREATER";
      else if(a.at(i)<b.at(i))
        return "LESS";
    }
    return "EQUAL";
  }
}

int main (){
  string a,b;
  cin >> a >> b;
  cout << comp(a,b) << endl;
}
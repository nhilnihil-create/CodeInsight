#include <bits/stdc++.h>
using namespace std;
int main(){
  string a;
  long ans=0;
  vector<int>vec;
  cin >> a;
  int roop = a.size();
  for (int i=0;i<roop;i++){
  	vec.push_back(a.at(i)-48);
  }
  
  reverse(vec.begin(),vec.end());
  vector<vector <int>>vect(roop);
  vect.at(0).push_back(roop-1);
  for(int i=0;i<roop;i++){
    if(i==0)
      continue;
    else{
      int w=0;
      vect.at(i)=vect.at(i-1);
      w=vect.at(i).at(i-1);
      vect.at(i).pop_back();
      vect.at(i).push_back(w-1);
      vect.at(i).push_back(w-1);
    }
  }
  for(int i=0;i<roop;i++){
    int counter=0;
    for(int q:vect.at(i)){
      //cout<<q<<endl;
      ans += vec.at(i)*pow(10,counter)*pow(2,q);
      counter++;
      //cout <<vec.at(i)<<" " <<ans << endl;
    }
  }      
  	cout << ans <<endl;
}
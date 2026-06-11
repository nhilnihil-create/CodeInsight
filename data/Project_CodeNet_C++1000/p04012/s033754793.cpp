#include<bits/stdc++.h>
using namespace std;

int main(){
  string w;
  cin >> w;
  vector<char> vec(w.size());
  for(int i = 0;i < w.size();i ++){
    vec.at(i) = w[i];
  }
  
  if((w.size() + 2) % 2 != 0){
    cout << "No" << endl;
  }
  
  else {
    
    bool hantei = true;
    
    //count(vec.begin(),vec.end(),'a');
    vector<char> yousosu = vec;
    sort(yousosu.begin(),yousosu.end());
    yousosu.erase(unique(yousosu.begin(), yousosu.end()), yousosu.end());
    for(int i = 0;i < yousosu.size();i ++){
      if((count(vec.begin(),vec.end(),yousosu[i]) + 2) % 2 != 0){
        hantei = false;
      }
    }
      if(hantei)cout << "Yes" << endl;
      else cout << "No" << endl;
  }
    
}
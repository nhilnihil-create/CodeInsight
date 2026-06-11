#include<bits/stdc++.h>
 
using namespace std;

int main(){
  int a,b;
  cin >> a>>b;
  int N;
  cin >> N;
  vector<int> c;
  for(int i = 0; i < N; i++){
    int tmp;
    cin >> tmp;
    for(int j = 0; j < tmp; j++){
      c.push_back(i+1);
    }
  }
  vector<vector<int>> v(a);
  int height = 0;
  for(int i = 0; i < a*b; i++){
    if(i % b < b -1){
      v.at(height).push_back(c[i]);
    } else { 
      v.at(height).push_back(c[i]);
      height++;
    }
  }
  
  for(int i = 0; i < a; i++){
    if(i % 2 == 0){
      for(int j = 0; j < v.at(i).size(); j++){
        if(j == v.at(i).size()-1){
          cout << v.at(i).at(j) << endl;
        } else {
          cout << v.at(i).at(j) << " ";
        }
      }
    } else {
      reverse(v.at(i).begin(), v.at(i).end());
      for(int j = 0; j < v.at(i).size(); j++){
        if(j == v.at(i).size()-1){
          cout << v.at(i).at(j) << endl;
        } else {
          cout << v.at(i).at(j) << " ";
        }
      }
    } 
  }
}
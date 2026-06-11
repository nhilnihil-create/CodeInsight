#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,M; cin>> N >>M;
  vector <pair<int,int>>gakusei;
  for(int i = 0; i < N; i++){
    int a,b; cin >> a >>b;
    gakusei.push_back(make_pair(a,b));
  }
  vector <pair<int,int>>point;
  for(int i = 0; i < M; i++){
    int a,b; cin >> a >>b;
    point.push_back(make_pair(a,b));
  }
  int min_distance = 9999999999999;
  int min_check;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      int tmp = abs(gakusei.at(i).first - point.at(j).first) + abs(gakusei.at(i).second - point.at(j).second); 
      if(min_distance > tmp){
        min_check = j + 1;
        min_distance = tmp;
      }
    }
   	cout << min_check << endl;
    min_distance = 9999999999999;
  }
}
  
  
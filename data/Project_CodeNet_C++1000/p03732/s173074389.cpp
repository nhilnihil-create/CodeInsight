#include<bits/stdc++.h>

using namespace std;

int main(){
  int N;
  long long W;
  cin >> N >> W;
  
  vector<vector<long long>> v(4, vector<long long>(1, 0));
  long long w;
  long long w_in, v_in;
  cin >> w_in >> v_in;
  w = w_in;
  v[0].push_back(v_in);
  for(int i = 1; i < N; i++){
    cin >> w_in >> v_in;
    
    v[w_in - w].push_back(v_in);
  }
  
  for(int j = 0; j <= 3; j++){
    sort((v[j].begin() + 1), v[j].end(), greater<long long>());
    for(int i = 1; i < v[j].size(); i++){
      v[j][i] += v[j][i - 1];
    }
  }
  
  long long value = 0;
  for(int i = 0; i < v[0].size(); i++){
    for(int j = 0; j < v[1].size(); j++){
      for(int k = 0; k < v[2].size(); k++){
        for(int l = 0; l < v[3].size(); l++){
          if(w * i + (w + 1) * j + (w + 2) * k + (w + 3) * l <= W){
            value = max(v[0][i] + v[1][j] + v[2][k] + v[3][l], value);
          }
        }
      }
    }
  }
  
  cout << value << endl;
  
  return 0;
}
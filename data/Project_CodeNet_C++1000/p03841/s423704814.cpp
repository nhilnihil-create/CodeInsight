#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<pair<int,int>> V;
  for(int i = 0; i < N; ++i){
    int x;
    cin >> x;
    --x;
    V.emplace_back(x,i+1);
  }
  sort(V.begin(), V.end());
  vector<int> A(N*N,-1);
  int l = 0;
  for(auto p : V){
    for(int i = 1; i < p.second; ++i){
      while(A[l] >= 0) ++l;
      A[l] = p.second;
    }
    if(l > p.first){
      cout << "No" << endl;
      return 0;
    }
    A[p.first] = p.second;
  }
  for(auto p : V){
    for(int i = 0; i < N-p.second; ++i){
      while(A[l] >= 0) ++l;
      if(l < p.first){
        cout << "No" << endl;
        return 0;
      }
      A[l] = p.second;
    }
  }
  cout << "Yes" << endl;
  for(int i = 0; i < N*N; ++i){
    cout << A[i];
    if(i+1 < N*N) cout << " ";
    else cout << endl;
  }
}

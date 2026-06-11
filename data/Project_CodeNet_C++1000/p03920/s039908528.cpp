#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int Ma;

bool dfs(int p, vector<int> v, int left){
  if(left==0){
    for(int i=0; i<v.size(); i++){
      cout << v[i] << endl;
    }
    cout << Ma << endl;
    return 1;
  }

  for(int i=p-1; i>0; i--){
    if((left-i)>=0){
      v.push_back(i);
      if(dfs(i,v,left-i)) return 1;
      v.pop_back();
    }
  }

  return 0;
}

int main() {
  int N;
  cin >> N;

  int k=1;
  for(int i=1; i<=1e7; i++){
    //cout << k << endl;
    if(N<k){
      Ma = i-1;
      break;
    }
    k += i;
  }
  vector<int> v;
  dfs(Ma,v,N-Ma);

}
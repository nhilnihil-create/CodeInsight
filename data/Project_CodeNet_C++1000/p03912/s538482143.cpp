#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc, char* argv[]){
  int n,m; cin >> n >> m;
  vector<vector<int>> x(m, vector<int>(0));
  for(int i = 0; i < n ; i++){
    int a; cin >> a;
    if(a % m == 0) x[0].push_back(a);
    else x[a%m].push_back(a);
  }
  int ans = 0;
  for(int i = 0; i < (x.size() - x.size()%2)/2 + 1; i++){
    if(i%m == 0) ans += (x[0].size() - (x[0].size()%2))/2;
    else if((i * 2) % m == 0) ans += (x[i].size() - x[i].size()%2)/2;
    else{
      int a,b;
      if(x[i].size() > x[m-i].size()){
        a = i;
        b = m - i;
      }
      else{
        a = m - i;
        b = i;
      }
      ans += x[b].size();
      int count = 0;
      sort(x[a].begin(), x[a].end());
      for(int j = 0; j < x[a].size()-1 ; j++){
        if(x[a].size() - x[b].size() >= count+2){
          if(x[a][j] == x[a][j+1]){
            count += 2;
            j++;
          }
        }
        else break;
      }
      ans += count/2;
    }
  }
  cout << ans << endl;
}

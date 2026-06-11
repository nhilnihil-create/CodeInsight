#include <iostream>
#include <vector>
#include <string>

#define rep(i,n) for(int i = 0; i < n; i++)

using namespace std;

int main(){
  int n, m, ind, lim, flag;

  cin >> n >> m;
  vector<string> vn(n);
  vector<string> vm(m);

  rep(i, n) cin >> vn[i];
  rep(i, m) cin >> vm[i];

  lim = n - m + 1;
  rep(i, lim){
      flag = 0;
      ind = vn[i].find(vm[0]);
      if(ind != string::npos){
          rep(j, m - 1){
              if(vm[j + 1] != vn[i + j + 1].substr(ind, m)){
                  flag = 1;
                  break;
              }
          }
          if(flag == 0){
              cout << "Yes" << endl;
              flag = 2;
              break;
          }
      }
  }
  if(flag != 2) cout << "No" << endl;

}
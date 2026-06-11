#include <bits/stdc++.h>
using namespace std;

int main(){
  const int Nw= 4;
  vector<vector<int>> data(Nw);
  int N,vi; int64_t W,w0,wi;
  cin >> N >> W;
  cin >> w0 >> vi;
  data.at(0).emplace_back(vi);

  for(int i=1; i<N; i++){
    cin >> wi >> vi;
    data.at(wi-w0).emplace_back(vi);
  }

  vector<vector<int>> cumsum(Nw);
  for(int i=0; i<Nw; i++){
    sort(data.at(i).begin(), data.at(i).end(), greater<int>());

    int sum= 0;
    cumsum.at(i).emplace_back(sum);
    for(int j=0; j<data.at(i).size(); j++){
      sum+= data.at(i).at(j);
      cumsum.at(i).emplace_back(sum);
    }
  }
  
  int ans= -1;
  for(int n0=0; n0<cumsum.at(0).size(); n0++){
    for(int n1=0; n1<cumsum.at(1).size(); n1++){
      for(int n2=0; n2<cumsum.at(2).size(); n2++){
        for(int n3=0; n3<cumsum.at(3).size(); n3++){
          int64_t w= w0*(n0+n1+n2+n3)+ n1+ 2*n2+ 3*n3;
          if(w <= W){
            ans= max(ans, cumsum.at(0).at(n0)+ cumsum.at(1).at(n1)+ cumsum.at(2).at(n2)+ cumsum.at(3).at(n3));
          }
        }
      }
    }
  }
  
  cout << ans << endl;
}
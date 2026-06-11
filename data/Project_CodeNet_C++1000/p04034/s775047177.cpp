#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  int N,M;
  cin >> N >> M;
  map<int, bool> m;
  m[0] = true;
  vector<int> v(N,1);

  for(int i = 0; i < M; i++){
    int tmp1,tmp2;
    cin >> tmp1 >> tmp2;
    tmp1--;
    tmp2--;
    v.at(tmp1)--;
    v.at(tmp2)++;

    if(m.count(tmp1) != 0){
      // xがあるかもしれないところが選ばれていた場合
      if(v.at(tmp1) == 0){
        m.erase(tmp1);
      }
      m[tmp2] = true;
    }
  }

  cout << m.size() << endl;
}

#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chkMin(T& a, T b){
  if(a > b){
    a = b;
    return true;
  }
  return false;
}

int main() {
  int num,point;
  long long tmp1, tmp2;
  cin >> num >> point;
  vector<pair<long long, long long>> pN(num);
  vector<pair<long long, long long>> pP(point);
  vector<long long> vec(num,0);
  
  for(int i = 0; i < num; i++){
    cin >> tmp1 >> tmp2;
    pN.at(i) = make_pair(tmp1, tmp2);
  }
  
  for(int i = 0; i < point; i++){
    cin >> tmp1 >> tmp2;
    pP.at(i) = make_pair(tmp1, tmp2);
  }
  
  for(int i = 0; i < num; i++){
    long long Min = 9999999999;
    for(int j = 0; j < point; j++){
      long long x1,y1,x2,y2;
      tie(x1, y1) = pN.at(i);
      tie(x2, y2) = pP.at(j);

      tmp1 = abs(x1 - x2);
      tmp2 = abs(y1 - y2);
      //Min = max(Min, tmp1 + tmp2);
      if(chkMin(Min, tmp1 + tmp2) == true){
        vec.at(i) = j+1;
      }
    }
  }
  
  for(int i = 0; i < num; i++){
    cout << vec.at(i) << endl;
  }
}

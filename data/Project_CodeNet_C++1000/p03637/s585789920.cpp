#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  int n, div_2 = 0, div_4 = 0, odd = 0;
  cin >> n;
  vector<ll> box(n);
  for(int i = 0; i < n; i++){
    cin >> box.at(i);
    if(box.at(i)%4 == 0) div_4++;
    else if(box.at(i)%2 == 0) div_2++;
    else odd++;
  }
  //4の倍数しか使わんでいいとき
  if(div_4 > box.size()/2-1){
    cout << "Yes" << endl;
    return 0;
  }
  //2の倍数しか使わんでいいとき
  else if(div_2 == box.size()){
    cout << "Yes" << endl;
    return 0;
  }
  //2の倍数と4の倍数の両方使うとき
  else if((double(box.size()-div_2)/2) <= div_4){
    cout << "Yes" << endl;
    return 0;
  }
  else{
    cout << "No" << endl;
    return 0;
  }
  
}
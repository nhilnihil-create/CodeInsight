#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin >> n;
  vector<int> box(9,0);
  for(int i = 0; i < n; i++){
    cin >> k;
    if(k < 400) box.at(0)++;
    else if(k>=400 && k<800) box.at(1)++;
    else if(k>=800 && k<1200) box.at(2)++;
    else if(k>=1200 && k<1600) box.at(3)++;
    else if(k>=1600 && k<2000) box.at(4)++;
    else if(k>=2000 && k<2400) box.at(5)++;
    else if(k>=2400 && k<2800) box.at(6)++;
    else if(k>=2800 && k<3200) box.at(7)++;
    else box.at(8)++;
  }
  int min_cnt = 0, max_cnt = 0;
  for(int i = 0; i < 8; i++){
    if(box.at(i) != 0) min_cnt++;
  }
  if(min_cnt == 0){
    cout << 1 << " " << box.at(8) << endl;
    return 0;
  }
  if(box.at(8) == 0){
    max_cnt = min_cnt;
  }
  else{
    max_cnt = min_cnt + box.at(8);
  }
  cout << min_cnt << " " << max_cnt << endl;
}
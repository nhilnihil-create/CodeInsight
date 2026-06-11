#include <bits/stdc++.h>
using namespace std;
int main(){
  int N; cin >>N;
  int s = 0;
  vector<bool> rate(8,false);
  for(int i = 0; i < N; i++){
    int a; cin >> a;
    if(a >= 3200)
      s++;
    else if(a >=2800)
      rate.at(7) = true;
    else if(a >=2400)
      rate.at(6) = true;
    else if(a >=2000)
      rate.at(5) = true;
    else if(a >=1600)
      rate.at(4) = true;
    else if(a >=1200)
      rate.at(3) = true;
    else if(a >=800)
      rate.at(2) = true;
    else if(a >=400)
      rate.at(1) = true;
    else 
      rate.at(0) = true;
  }
  int min_num = 0;
  for(int i = 0; i < 8; i++){
    if(rate.at(i)) min_num++;
  }
  cout << max(1,min_num) << " " <<max(1,min_num + s) << endl;
}
 

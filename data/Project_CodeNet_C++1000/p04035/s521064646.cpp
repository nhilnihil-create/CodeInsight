#include <iostream>
#include <vector>

using namespace std;
#define ll long long



int main(void){
  ll num,larg;
  cin >> num >> larg;
  vector<ll> lon(num);
  for(int i = 0;i < num;i ++){
    cin >> lon[i];
  }
  for(int i = 0;i < num-1;i ++){
    if(lon[i]+lon[i+1]>=larg){
      cout << "Possible" << endl;
      for(int j = 0;j < i;j ++){
        cout << j+1 << endl;
      }
      for(int j = num-1;j > i;j--){
        cout << j << endl;
      }
      return 0;
    }
  }
  cout << "Impossible" << endl;
  return 0;
}
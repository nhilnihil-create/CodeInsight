#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main(){
  string a,b;
  cin >> a >> b;
  int aSize = a.size();
  int bSize = b.size();
  int equalFlag = true;
  if(aSize > bSize){
    cout << "GREATER" << endl;
    equalFlag = false;
  }else if(aSize < bSize){
    cout << "LESS" << endl;
    equalFlag = false;
  }else{
    rep(i,aSize){ //同じ桁数だからb.Sizeでも当然おｋ
      if(a[i]==b[i]) continue;
      if(a[i]>b[i]){
        cout << "GREATER" << endl;
        equalFlag = false;
        break;
      }
      if(a[i] < b[i]){
        cout << "LESS" << endl;
        equalFlag = false;
        break;
      }
    }
  }
  if(equalFlag) cout << "EQUAL" << endl;
}
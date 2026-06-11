#include<bits/stdc++.h>
using namespace std;


int main(){
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  int sita=max(a,c);
  int ue=min(b,d);
  if(ue-sita<=0) cout << "0" << endl;
  else cout << ue-sita << endl;
  return 0;
}

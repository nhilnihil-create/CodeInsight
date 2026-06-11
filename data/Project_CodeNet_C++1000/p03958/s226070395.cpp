#include<bits/stdc++.h>
using namespace std;


int main(){
  int k,t;
  cin >> k >> t;
  vector<int> a(t);
  for(int i=0;i<t;++i) cin >> a[i];

  sort(a.rbegin(),a.rend());
  int cal=a[0];
  for(int i=1;i<t;++i){
    if(cal-a[i]>=0) cal-=a[i];
    else{
      int tmp=a[i]-cal;
      cal=tmp;
    }
  }
  if(cal>0)cal--;
  cout << cal << endl;
  return 0;

}

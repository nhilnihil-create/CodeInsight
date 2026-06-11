#include <bits/stdc++.h>
using namespace std;
 



int main() {
 

  int n;
  cin>>n;

  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a.at(i);
  }

  int cnt4=0,cnt2=0;
  //4の倍数
  //4の倍数出ないが、2の倍数/2
  //の合計がn/2より大きい
  for(int i=0;i<n;i++){
    if(a.at(i)%4==0)
      cnt4++;
    else if(a.at(i)%2==0)
      cnt2++;
  }

  if(cnt4+cnt2/2>=n/2)
    cout<<"Yes"<<endl;
  else 
    cout<<"No"<<endl;

	return 0;
}
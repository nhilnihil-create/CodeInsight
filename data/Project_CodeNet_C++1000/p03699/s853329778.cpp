#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
 
  int64_t n;
  cin>>n;

 
  vector<int64_t> s(n);
  for(int i=0;i<n;i++){
    cin>>s.at(i);
  }

  sort(s.begin(),s.end());

  int64_t sum=0;
  bool flg=false;
  int64_t wk=0;
  for(int i=0;i<n;i++){
    sum+=s.at(i);

    if(flg==false && s.at(i)%10!=0){
      flg=true;
      wk=s.at(i);
    }

  }

  if(flg==false)
    cout<<0<<endl;
  else if(sum%10!=0)
    cout<<sum<<endl;
  else
    cout<<sum-wk<<endl;

	return 0;
}
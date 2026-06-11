#include <bits/stdc++.h>
using namespace std;

template<typename T>
void fin(T a){
  cout<<a<<endl;
  exit(0);
}

signed main(){
  int n;cin>>n;
  vector<int> v(n);
  for(int i=0;i<n;i++)cin>>v[i];
  sort(v.begin(),v.end());
  int migi=0;bool mfw=!(n&1);
  for(int i=0;i<n;i++){
    int z=n-1-i,m=v[i]-1;
    if(!(i&&v[i]==v[i-1])){
      if(m>=z){
        if(m==z)fin("Second");
        if(migi==z&&mfw)fin("First");
        if((m+z)&1)fin("First");
        fin("Second");
      }
      mfw=(m+z)&1;
      migi=m;
    }
    else if(m==z)fin(mfw?"First":"Second");
  }
  fin(mfw?"First":"Second");
}

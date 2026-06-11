#include <bits/stdc++.h>
using namespace std;
 


int main() {
 
  int64_t n;
  cin>>n;

  vector<int64_t> t(n);
  for(int i=0;i<n;i++){
    cin>>t.at(i);
  }

  int64_t m;
  cin>>m;

  for(int i=0;i<m;i++){
    int64_t p,x;
    cin>>p>>x;

    int64_t sum=0;
    for(int j=0;j<n;j++){
      if(j==p-1)
        sum+=x;
      else
        sum+=t.at(j);
    }
    cout<<sum<<endl;
  }


	return 0;
}


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int main(){
  int n,ans=0,l[210],i;
  cin >> n;
  n=n*2;
  for(i=0;i<n;i++){
    cin >> l[i];
  }
  sort(l,l+n);
  for(i=0;i<n;i++){
    if(i%2==0){
      ans+=l[i];
    }
  }
  cout << ans << endl;
  return 0;
}
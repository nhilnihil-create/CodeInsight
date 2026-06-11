#include <iostream>
#include<algorithm>
#include<functional>
using namespace std;
int main(void) {
  int N;
  int K;
  int l[50];
  cin>>N>>K;
  int ans=0;
  for(int i=0;i<N;i++){
    cin>>l[i];
  }
  sort(l,l+N,greater<int>());
  for(int a=0;a<K;a++){
    ans+=l[a];
  }
  cout<<ans<<endl;
}
    
    
  

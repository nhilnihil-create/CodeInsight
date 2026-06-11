#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  vector<int> a(N);
  for(int i=0;i<N;i++){
    cin>>a.at(i);
  }
  
  set<int> color;
  int rainbow=0;
  for(int x:a){
    x/=400;
    if(x<8){
      color.insert(x);
    }
    else
      rainbow++;
  }
  int ans = color.size();
  if(ans!=0)
    cout<<ans<<" "<<(ans+rainbow)<<endl;
  else
    cout<<"1"<<" "<<rainbow<<endl;
}

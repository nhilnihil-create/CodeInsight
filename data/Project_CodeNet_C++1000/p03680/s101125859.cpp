#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,p=1,cnt=0;
  cin >> N;
  bool ok=false;
  vector<int> data(N+1);
  data.at(0)=0;
  for(int i=1;i<=N;i++){cin>>data.at(i);}
  for(int i=0;i<=N;i++){
    cnt++;
    if(data.at(p)==2){
      ok=true;
      break;
    }else{
      p=data[p];
    }
  }
  cout<<(ok ? cnt : -1)<<endl;
}

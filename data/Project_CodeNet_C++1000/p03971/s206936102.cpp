#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,A,B;cin>>N>>A>>B;
  string S;cin>>S;
  int l=S.size();
  int count=0;
  int ans=0;
  for(int i=0;i<l;i++){
    if(S.at(i)=='a'){
      count++;
      if(count<=A+B) cout<<"Yes"<<endl;
      else{
        cout<<"No"<<endl;
        count--;
      }
    }
    else if(S.at(i)=='b'){
      count++;
      ans++;
      if(count<=A+B && ans<=B) cout<<"Yes"<<endl;
      else{
        cout<<"No"<<endl;
        count--;
        ans--;
      }
    }
    else cout<<"No"<<endl;
  }
}

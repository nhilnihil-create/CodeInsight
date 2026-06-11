#include <bits/stdc++.h>
using namespace std;

int main(){
  string s,t;
  cin >> s;

  int ans=110;
  for(char x='a';x<'z'+1;x++){
    int count=0;
    int temp=0;
    t=s+x;  
    //cout<<t<<" "<<t.length()<<endl;
    for(int i=0;i<t.length();i++){
      //cout<<count<<" "<<temp<<endl;
      if(t.at(i)==x){
        count=max(count,temp);
        temp=0;
      }
      else{
        temp++;
      }
    }
    //cout<<x<<" "<<count<<endl;
    ans=min(ans,count);
  }
  cout<<ans<<endl;
  return 0;
}

    
#include<bits/stdc++.h>
using namespace std;
int main(){
      string s;
      cin>>s;
      int flag=0;
      for(int i=0;i<s.length();i++){
        if(s[i]=='9'){
            flag=1;
            break;
        }
      }
      if(flag==1){
        cout<<"Yes"<<endl;
      }
      else{
        cout<<"No"<<endl;
      }
      return 0;
}

#include <iostream>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main() {
  int n,left=0,right=0,l=0,r=0;
  string s;
  cin>>n>>s;
  char c=s[0];
  rep(i,n){
     if(c!=s[i]){
        if(s[i]=='('){
           left+=max(0,l-r);
           r=max(0,r-l);
           l=0;
        }
        c=s[i];
     }
     c==')'?l++:r++;
  }
  left+=max(0,l-r);
  right=max(0,r-l);
  rep(i,left) cout<<"(";
  cout<<s;
  rep(i,right) cout<<")";
    return 0;
}
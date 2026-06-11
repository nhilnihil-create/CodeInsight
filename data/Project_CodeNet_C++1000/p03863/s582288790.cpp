#include <iostream>
using namespace std;

int main() {
  string s; cin>>s;
  if ((s[0]==s[s.size()-1])^(s.size()%2==0)) {
    cout<<"Second"<<endl;
  } else {
    cout<<"First"<<endl;
  }
  /*
  char a[2]={s[0],s[1]}; bool p=true;
  for(int i=2;i<s.size()&&p==true;i++) {
    if (!(s[i] == a[i%2])) p=false;
  }
  //cout<<p<<endl;
  if (p==false) {
    if (s.size()%2==0) cout<<"Second"<<endl;
    else cout<<"First"<<endl;
  } else {
    // 一つも取れない
    cout<<"Second"<<endl;
  }*/
}
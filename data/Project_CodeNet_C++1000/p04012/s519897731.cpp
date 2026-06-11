#include<iostream>
#include<vector>
#include<string>
using namespace std;
void yn(bool ok) {
  if(ok) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}


int main(){
  string s;
  cin>>s;
  vector<int> a(26,0);
  for(int i=0;i<s.size();i++) a[s[i]-'a']++;
  bool ok=1;
  for(int i=0;i<26;i++) if(a[i]%2==1) ok=0;
  yn(ok);
}

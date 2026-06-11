 #include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  vector<int>ad(26);
  for(int i=0;i<26;i++){
    ad[i]=0;
  }
  for(int i=0;i<s.size();i++){
    ad[s[i]-'a']++;
  }
  for(int i=0;i<26;i++){
    if(ad[i]==0){
      cout<<char('a'+i)<<endl;
      return 0;
    }
  }
  cout<<"None"<<endl;
}
    

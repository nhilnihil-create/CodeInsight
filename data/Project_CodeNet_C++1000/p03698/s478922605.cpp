#include<bits/stdc++.h>
using namespace std;

int main(void){
   string s;
   cin>>s;
   set<char> dict;
   for(int i=0;i<s.size();i++){
      dict.insert(s[i]);
   }
   if(dict.size()==s.size()) cout<<"yes"<<endl;
   else cout<<"no"<<endl;
}


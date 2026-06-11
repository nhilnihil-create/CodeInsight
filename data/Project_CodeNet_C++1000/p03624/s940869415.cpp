#include<bits/stdc++.h>
using namespace std;

int main(){
string S;cin>>S;
vector<bool> alphabets(26,false);
for(int i=0;i<S.size();i++){
if(!alphabets[S[i]-'a'])alphabets[S[i]-'a']=true;
}
for(int i=0;i<26;i++)if(!alphabets[i]){printf("%c",'a'+i);return 0;}
cout<<"None";
}
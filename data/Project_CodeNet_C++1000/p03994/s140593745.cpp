#include <bits/stdc++.h>
using namespace std;


int main() {
string s;
long K;
cin>>s>>K;
long n=s.size();
string ans="";
for(int i=0;i<n;i++){
  if(K>=('z'-s[i]+1)&&s[i]!='a'){
    K-=int('z'-s[i]+1);
    s[i]='a';
  }

}
s[n-1]+=K%26;
//cout<<K<<endl;
cout<<s<<endl;
}

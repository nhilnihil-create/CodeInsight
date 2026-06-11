
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;

bool check(string s){
    vector<int> v(26,0);
    for(int i=0;i<s.length();i++)v[s[i]-'a']++;
    int m=0;
    for(int i=0;i<26;i++)m=max(v[i],m);
   if( m>s.length()/2)return true;
   else return false;
}

int main(){
string s;cin>>s;long long n=s.length();
for(int i=0;i<n-1;i++){
    if(check(s.substr(i,2))){cout<<i+1<<" "<<i+2;return 0;}
}
for(int i=0;i<n-2;i++){
    if(check(s.substr(i,1+2))){cout<<i+1<<" "<<i+3;return 0;}
}
cout<<-1<<" "<<-1;
}
#include <bits/stdc++.h>
#define r(i,n) for(int i = 0; i<n; i++)
using namespace std;
int main(){
  int count=0;
  string s1,s2="CODEFESTIVAL2016";
  cin >> s1;
  r(i,s1.length()){
    if(s1.at(i)!=s2.at(i))count++;
  }
  cout << count<<endl;
}
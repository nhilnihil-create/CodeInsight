#include<bits/stdc++.h>
using namespace std;
int main(){
int N,A,B;
cin >> N >> A >> B;
string s;
cin >> s;
string a[100010];
int sum_d = 0;
int sum_f = 0;
for(int i = 0; i< s.size(); i++){
  if(s.at(i) == 'c') a[i] = "No";
  else if(s.at(i) == 'a'){
    if(A+B>sum_d){
      a[i] ="Yes";
      sum_d++;
    }
    else{
      a[i] ="No";
    }
  }
  else{
    if(A+B>sum_d && B > sum_f){
      a[i] ="Yes";
      sum_d++;
      sum_f++;
    }
    else{
      a[i] ="No";
    }
  }
}
for(int i = 0; i<s.size();i++){
  cout << a[i] << endl;
}
}
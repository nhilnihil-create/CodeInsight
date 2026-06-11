#include <bits/stdc++.h>
#define r(i,n) for(int i = 0; i<n; i++)
using namespace std;
int main(){
  int h,w;
  cin>>h>>w;
  r(i,h*w){
    string s;
    cin >> s;
    if(s=="snuke"){
      char ch = 'A';
      ch+=i%w;
      cout << ch <<i/w+1<<endl;
      break;
    }
  }
}
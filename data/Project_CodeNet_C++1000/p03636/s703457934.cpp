#include<bits/stdc++.h>
#define PI 3.141592653589
#define ll long long
using namespace std;

int main(){
  string s;
  cin >> s;

  if(s.size() > 2){
    cout << s.at(0) << s.size() - 2 << s.at(s.size()-1);
  }
  else cout << s;
}
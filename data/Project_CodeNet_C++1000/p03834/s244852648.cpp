#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<iomanip>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
int main(){
  string s;
  cin >> s;
  int a = s.size();
  rep(i, 0, a){
    if(i == 5 || i == 13){
      cout << " ";
    }
    else{
      cout << s[i];
    }
  }
}
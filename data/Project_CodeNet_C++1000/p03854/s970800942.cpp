#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define ssort(a) sort(a.begin(), a.end())
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

int main(){
  string s;
  cin >> s;
  int n=s.size();
  int num=0;
  while(num<n){
    if(num+4<n && s.substr(num, 5)=="dream"){
      if(num+4==n-1){
        break;
      } else {
        if(num+6>=n){
          cout << "NO" << endl;
          return 0;
        } else if(s.substr(num, 7)=="dreamer"){
          if(num+7>=n){
            break;
          } else if(s[num+7]=='a'){
            num+=5;
          } else {
            num+=7;
          }
        } else {
          num+=5;
        }
      }
    } else if(num+4<n && s.substr(num, 5)=="erase"){
      if(num+4==n-1){
        break;
      } else {
        if(num+5>=n){
          cout << "NO" << endl;
          return 0;
        } else if(s.substr(num, 6)=="eraser"){
          num+=6;
        } else {
          num+=5;
        }
      }
    } else {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}

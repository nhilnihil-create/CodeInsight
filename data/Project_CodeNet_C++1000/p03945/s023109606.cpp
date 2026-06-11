#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<n+1;i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end())
typedef long long ll;
typedef pair<int,int> P;

int main(){
  string s;
  cin >> s;
  int n = s.size();
  string t = "";
  rep(i,n){
    if(i == 0) t.push_back(s[i]);
    if(i > 0) if(s[i] != s[i-1]) t.push_back(s[i]);
  }
  cout << t.size()-1 << endl;
}
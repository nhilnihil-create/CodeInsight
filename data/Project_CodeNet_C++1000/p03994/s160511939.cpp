#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
  string s;
  int k;

  cin>>s>>k;
  int i = 0;
  while(i < s.size()){
    if(k >= ('z' - s[i] + 1) % 26){
      k -= ('z' - s[i] + 1) % 26;
      s[i] = 'a';
    }
    i++;
  }
  if(k) s[s.size() - 1] = 'a' + (s[s.size() - 1]  - 'a' + k) % 26;
  cout << s << endl;
}
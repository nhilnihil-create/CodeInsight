#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
  string s;
  cin>>s;
  int n=s.size();
  cout<<((s[0]==s[n-1])^(n%2==0)?"Second":"First")<<endl;
}
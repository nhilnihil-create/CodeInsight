#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;
  int n=s.size();
  if(s[0]==s[n-1]){
    if(n%2==1) cout << "Second" << endl;
    else cout << "First" << endl;
  }
  else{
    if(n%2==0) cout << "Second" << endl;
    else cout << "First" << endl;
  }

  
  return 0;
    

}

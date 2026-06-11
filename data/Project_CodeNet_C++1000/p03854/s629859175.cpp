#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int> 


int main(){
  string S; cin >> S;

  while (S.size()){
    if (S.size()>=5 && (S.substr(S.size()-5)=="dream" || S.substr(S.size()-5)=="erase")) S.erase(S.size()-5);
    else if (S.size()>=6 && S.substr(S.size()-6)=="eraser") S.erase(S.size()-6);
    else if (S.size()>=7 && S.substr(S.size()-7)=="dreamer") S.erase(S.size()-7);
    else break;
    
  }

  if (S.size()==0) cout << "YES" << endl;
  else cout << "NO" << endl;

  return 0;
}

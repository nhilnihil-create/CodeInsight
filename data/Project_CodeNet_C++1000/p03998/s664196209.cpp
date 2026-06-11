#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  vector<string> s(3);
  rep(i,3) cin >> s.at(i);

  vector<int> p(3,0);
  int now=0;

  while(1){
    if(p.at(now)==s.at(now).size()) break;

    int po = p.at(now);
    p.at(now)++;
    char next = s.at(now).at(po);
    
    //cout << now <<" " <<next << endl;
    
    if(next=='a') now=0;
    else if(next=='b') now=1;
    else now=2;
  }

  if(now==0) cout << "A";
  else if(now==1) cout << "B";
  else cout << "C";
  
}
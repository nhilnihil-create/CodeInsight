#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  string sa,sb,sc; cin >> sa >> sb >> sc;

  const int a = 'a';
  const int b = 'b';
  const int c = 'c';

  int next = sa[0];
  sa.erase(sa.begin(),sa.begin()+1);
  int num = 1;
  
  //while(sa.size()>0 && sb.size()>0 && sc.size()>0){
  while(1){
    switch(next){
    case a:
      if(sa.size()==0){
	cout << "A" << endl;
	return 0;
      }
      next = sa[0];
      sa.erase(sa.begin(),sa.begin()+1);
      break;
    case b:
      if(sb.size()==0){
	cout << "B" << endl;
	return 0;
      }
      next = sb[0];
      sb.erase(sb.begin(),sb.begin()+1);
      break;
    case c:
      if(sc.size()==0){
	cout << "C" << endl;
	return 0;
      }
      next = sc[0];
      sc.erase(sc.begin(),sc.begin()+1);
    }
  }
  
  return 0;
}

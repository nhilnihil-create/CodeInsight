#include<bits/stdc++.h>
#define REP(i,n) for(int i = 0;i < (n);i++)
#define P pair<int,int>
#define pb push_back
#define mk make_pair
using namespace std;
const int INF = 1 << 20;

typedef long long ll;




int main(){
  int h,w;
  cin >> h >> w;
  string s[h][w];
  int a = 1,b = 0;;
  char c = 'A';
  REP(i,h){
    REP(j,w){
      cin >> s[i][j];
      if(s[i][j] == "snuke"){
	a = i;
	b = j;
	
      }
    }
  }
  c = 'A'+b;
  cout  << c << a+1 << endl;
  return 0;
}

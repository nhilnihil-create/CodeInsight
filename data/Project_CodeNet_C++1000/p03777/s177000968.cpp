#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<n+1;i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end())
typedef long long ll;

bool HD(char c){
  if(c == 'H') return 1;
  if(c == 'D') return 0;
}

int main(){
  char a,b;
  cin >> a >> b;
  if(HD(a)^HD(b)) cout << "D" << endl;
  else cout << "H" << endl;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end());
#define vecmin(A) *min_element(A.begin(),A.end());
#define vecmax(A) *max_element(A.begin(),A.end());
typedef long long ll;

int main(){
  int a,b;
  char c;
  cin >> a >> c >> b;
  if(c == '+') cout << a+b << endl;
  if(c == '-') cout << a-b << endl; 
}
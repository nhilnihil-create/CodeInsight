#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define int_Max 2147483647
#define ll_Max 9223372036854775807
#define REP(i,f,n) for(int i=f; i<(n); i++)

int main()
{
  int ans = 0;
  int n;
  cin >> n;
  int a[n], a2[n];
  REP(i,0,n){
    cin >> a[i];
    a2[i] = -1;
  }
  int next_p = a[0];
  do{
    ans++;
    a2[next_p - 1] = ans;
    next_p = a[next_p - 1];
    if(a2[next_p - 1] != -1)break;
  }while(a2[1]==-1);


  cout << a2[1] << endl;

  //--debug : end_stoper
  //string end_stoper; cin >> end_stoper;

  return 0;
}
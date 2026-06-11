#include <bits/stdc++.h>
using namespace std;

#define ll long long

signed main() {
  int A,B,C;
  cin >> A >> B >> C;
  int cnt1=0,cnt2=0;
  if(A==5)
  {
    cnt1 += 1;
  }
  else if(A==7)
  {
    cnt2 += 1;
  }

  if(B==5)
  {
    cnt1 += 1;
  }
  else if(B==7)
  {
    cnt2 += 1;
  }

  if(C==5)
  {
    cnt1 += 1;
  }
  else if(C==7)
  {
    cnt2 += 1;
  }
  if(cnt1==2 && cnt2==1)
  {cout << "YES" << endl;}
  else{cout << "NO" << endl;}
}

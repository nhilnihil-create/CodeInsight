#include <bits/stdc++.h>
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) FOR(i, 0, n)
#define ll long long
using namespace std;

const ll P = 1000000007;
int gcd(int a, int b) { return b != 0 ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }

int main()
{
  cout << fixed << setprecision(10);
  string A,B,C;
  cin >> A >> B >> C;
  int a = A.size();
  int b = B.size();
  int c = C.size();
  rep(i,a/2)
  {
    swap(A[i],A[a-i-1]);
  }
  rep(i,b/2)
  {
    swap(B[i],B[b-i-1]);
  }
  rep(i,c/2)
  {
    swap(C[i],C[c-i-1]);
  }
  char next = 'a';
  rep(i,a+b+c)
  {
    if(next=='a')
    {
      int aa = A.size();
      if(aa==0)
      {
        cout << "A" << endl;
        return 0;
      }
      if(A[aa-1]=='a') next = 'a';
      else if(A[aa-1]=='b') next = 'b';
      else if(A[aa-1]=='c') next = 'c';
      A.pop_back();
    }
    else if(next=='b')
    {
      int bb = B.size();
      if(bb==0)
      {
        cout << "B" << endl;
        return 0;
      }
      if(B[bb-1]=='a') next = 'a';
      else if(B[bb-1]=='b') next = 'b';
      else if(B[bb-1]=='c') next = 'c';
      B.pop_back();
    }
    else if(next=='c')
    {
      int cc = C.size();
      if(cc==0)
      {
        cout << "C" << endl;
        return 0;
      }
      if(C[cc-1]=='a') next = 'a';
      else if(C[cc-1]=='b') next = 'b';
      else if(C[cc-1]=='c') next = 'c';
      C.pop_back();
    }
  }
  return 0;
}

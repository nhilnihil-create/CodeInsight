#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define SORT(v) sort(v.begin(), v.end());
#define RSORT(v) sort(v.rbegin(), v.rend());
#define REVERSE(v) reverse(v.begin(), v.end());

template <typename T>
void printlnVector(T v)
{
  rep(i, v.size())
  {
    cout << v[i] << endl;
  }
}

template <typename T>
void printVector(T v)
{
  rep(i, v.size())
  {
    cout << v[i] << " ";
  }
  cout << endl;
}

int main()
{
  int N;
  cin >> N;
  vector<int> T(N), A(N);
  rep(i, N)
  {
    cin >> T[i];
  }

  rep(i, N)
  {
    cin >> A[i];
  }

  bool is_ok = true;
  vector<int> mountain_hight(N, -1);
  mountain_hight[0] = T[0];
  rep(i, N - 1)
  {
    if(T[i] < T[i + 1])
      mountain_hight[i + 1] = T[i + 1];
  }
  REVERSE(A);
  REVERSE(mountain_hight);
  
  rep(i, N)
  {
    if(mountain_hight[i] != -1 && mountain_hight[i] > A[i])
      is_ok = false;
  }

  if(mountain_hight[0] == -1)
    mountain_hight[0] = A[0];
  else if(mountain_hight[0] != A[0])
    is_ok = false;

  rep(i, N - 1)
  {
    if(A[i] < A[i + 1])
    {
      if(mountain_hight[i + 1] == -1)
        mountain_hight[i + 1] = A[i + 1];
      else if(mountain_hight[i + 1] != A[i +1]) 
        is_ok = false;
    }
  }

  if(!is_ok)
  {
    cout << 0 << endl;
    return 0;
  }

  REVERSE(A);
  REVERSE(mountain_hight);

  int mod = 1e9 + 7;
  long long ans = 1;
  rep(i, N)
  {
    if(mountain_hight[i] == -1)
    {
      ans *= min(T[i], A[i]);
      ans %= mod;
    }
  }
  cout << ans << endl;
  return 0;
}
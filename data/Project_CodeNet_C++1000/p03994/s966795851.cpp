#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
int main()
{
  string s;
  int k; 
  cin >> s >> k;
  int i;
  int left = k;
  int n = s.size();
  rep(i,n-1)
  {
    if(s[i] == 'a')continue;
    if(left >= 'z'-s[i]+1)
    {
      left -= 'z'-s[i]+1;
      s[i] = 'a';
    }
  }
  left %= 26;
  s[n-1] -= 26;
  s[n-1] += left;
  if(s[n-1] < 'a') s[n-1] += 26;
  cout << s << endl;
}


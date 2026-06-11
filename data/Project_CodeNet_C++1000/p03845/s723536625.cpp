#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std; //std::の省略のため
using ll = long long;

int main()
{
  int n, m;
  cin >> n;

  ll t[n];

  for(int i=0; i<n; i++)
    cin >> t[i];

  cin >> m;

  ll x[m], p[m];

  for(int i=0; i<m; i++)
    cin >> p[i] >> x[i];

  ll time = 0;

  for(int i=0; i<m; i++){
    time = 0;
    for(int j=0; j<n; j++){
      if(j == p[i]-1) 
        time += x[i];
      else
        time += t[j];
    }

    cout << time << endl;
  }

}

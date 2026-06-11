#include<bits/stdc++.h>

using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  
  vector<long long> eff(2 * m, 0), num(2 * m, 0);
  for(int i = 1; i < n; i++){
    ++num[a[i - 1]];
    --num[a[i] + (a[i] >= a[i - 1] ? 0 : m)];
    
    --eff[a[i - 1]];
    eff[a[i] + (a[i] >= a[i - 1] ? 0 : m)] -= (m + a[i] - a[i - 1] - 1) % m;
  }
  
  for(int i = 1; i < 2 * m; i++) num[i] += num[i - 1];
  
  for(int i = 1; i < 2 * m; i++) eff[i] += eff[i - 1] + num[i];
  
  long long m_eff = 0;
  for(int i = 0; i < m; i++) m_eff = max(eff[i] + eff[i + m], m_eff);
  
  m_eff = -m_eff;
  
  for(int i = 1; i < n; i++){
    m_eff += (m + a[i] - a[i - 1]) % m;
  }
  
  cout << m_eff << endl;
  
  return 0;
}
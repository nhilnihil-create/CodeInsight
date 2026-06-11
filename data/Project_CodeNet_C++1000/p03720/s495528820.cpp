#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n, m;
   cin >> n >> m;
   vector<int>a(m);
   vector<int>b(m);
   for(int i = 0; i < m; i++) cin >> a[i] >> b[i];
   vector<int>c(n);
   for(int i = 0; i < m; i++){
      c[a[i]-1] += 1;
      c[b[i]-1] += 1;
   } 
   for(int i = 0; i < n; i++)cout << c[i] << endl;
}


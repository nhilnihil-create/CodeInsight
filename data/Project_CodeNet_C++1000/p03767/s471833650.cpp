#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
int n;
cin >> n;
vector<int>a(3 * n);
for (int i = 0; i < 3 * n; i++)
{
  cin >> a.at(i);
}
sort(a.begin(), a.end());
reverse(a.begin(), a.end());
ll ans = 0;
int j = 0;
int count = 0;
for (int i = 1; count < n; i += 2)
{
    ans += a[i];
    count++;
}


  cout << ans << endl;
}
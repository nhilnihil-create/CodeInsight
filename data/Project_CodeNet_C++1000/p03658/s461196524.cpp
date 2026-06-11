#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){

int n,k;
cin >> n >> k;
int l[n];
for (int i = 0; i < n; i++)
{
  cin >> l[i];
}

sort(l, l + n, greater<int>());

int length = 0;
for (int i = 0; i < k; i++)
{
  length += l[i];
}

cout << length << endl;
}
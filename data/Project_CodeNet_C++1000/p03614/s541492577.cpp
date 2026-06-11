#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;


int main()
{
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  int n;
  cin >> n;
  int cnt = 0;
  int x;
  int res = 0;
  for(int i = 0;i < n;i++){
    scanf("%d", &x);
    if(x == i + 1){
      cnt++;
    }else{
      res += (cnt + 1) / 2;

      cnt = 0;
    }
  }
  res += (cnt + 1) / 2;
  cout << res;
}


#include<bits/stdc++.h>
#define rep(i,f,n) for(int i=(f); (i) < (n); i++)
#define repe(i,f,n) for(int i=(f); (i) <= (n); i++)
using namespace std;

typedef long long ll;
ll INF = 1LL << 60;

int 
main() 
{

  int n; cin >> n;
  vector<int> arr(n);
  rep(i, 0, n) cin >>arr[i];

  int mul4_num = 0;
  int odd_num = 0;
  rep(i, 0, n){
    if(arr[i] % 2 != 0) odd_num++;
    if(arr[i] %4 == 0) mul4_num++;
  }

  if((n % 2 == 0) && (odd_num <= mul4_num)){
    cout << "Yes" << endl;
  } else if((n % 2 != 0) && (odd_num - 1 <= mul4_num)){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  

  return 0;
}



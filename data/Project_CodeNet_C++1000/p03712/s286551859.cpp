#include<bits/stdc++.h>
#define int long long
#define vi vector<int>
#define pb push_back
#define log(x,b) (log(b)/log(x))
#define rep(i,x,y) for(int i=(x);i<(y);i++)
using namespace std;

const int mod=1e9+7;

int32_t main()
{
    int n,m;
    cin>>n>>m;
    vector<string>a(n);
    for(int i=0;i<n;i++){
        cin>>a.at(i);
    }
      for (int i = 0; i < n + 2; i++)
  {
    if (i == 0 || i == n + 1) {
      for (int j = 0; j < m + 2; j++)
      {
        cout << '#';
      }
      cout << endl;
    } else {
      cout << '#' << a.at(i - 1) << '#' << endl;
    }
  }
    return 0;
}

#include<bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)n; i++)
#define REPvec(itr, mp) for(auto itr = mp.begin();itr != mp.end(); itr ++)
#define all(x) x.begin(), x.end()
#define MOD 1000000007//1e9+7
using namespace std;
typedef long long ll;
typedef vector<int >    vecint;
typedef vector<string > vecstr;
int main()
{
  int a, b;
  cin >> a >> b;
  if(a + b >= 10){
    cout << "error" << endl;
  }else{
    cout << a + b << endl;
  }

}
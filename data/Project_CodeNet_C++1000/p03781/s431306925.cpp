#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<stack>
#include<string>

using namespace std;
const int INF = 1<<30;
typedef long long int ll;

int main(){
  int x;cin>>x;x*=2;
  int n = (int)sqrt(x);
  while(n*(n-1)>=x)n--;
  while(n*(n+1)<x)n++;
  cout << n << endl;
}

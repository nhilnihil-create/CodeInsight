#include <iostream>
#include <cctype>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <string>
#include <functional>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <bitset>
#define pb push_back
#define YES cout<<"YES"<<endl
#define Yes cout<<"Yes"<<endl
#define NO cout<<"NO"<<endl
#define No cout<<"No"<<endl
#define INF (1<<10)
#define MOD 1000000007
typedef long long ll;
using namespace std;

int main() {
    int x;
    cin>>x;
    int t=0, i=1;
    while(1){
      t+=i;
      if(x==t){
        cout<<i<<endl;
        break;
      }
      else if(x<t){
        cout<<i<<endl;
        break;
      }
      i++;
    }
    return 0;
}

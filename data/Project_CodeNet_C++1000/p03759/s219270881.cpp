#include <iostream>
#include <string>
#include <unordered_map>
#include <stdio.h>
#include <list>
#include <vector>
#include <algorithm>
#include <stack>
#include <climits>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ALL(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100000000;

int main()
{
   int a,b,c;
   cin >> a >> b >> c;
   if(b-a==c-b)cout<<"YES"<<endl;
   else cout<<"NO"<<endl;
   
   return 0;
}
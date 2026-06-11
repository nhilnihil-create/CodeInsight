#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <utility>
typedef long long ll;
using namespace std;
#define maxn 200000

int main()
{
    ll n,m;
   cin>>n>>m;
   if(max(n,m)-min(n,m)>=2)
   {
       printf("Alice\n");
   }
   else printf("Brown\n");
}




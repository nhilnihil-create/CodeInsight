#include<bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i=0 ; i<(n) ; i++)
#define repr(i,n) for(int i=(n) ; i>=0 ; i--)
#define FOR(i,m,n) for(int i=(m) ; i<(n) ; i++)
#define FORR(i,m,n) for(int i=(m) ; i>=(n) ; i--)

#define All(x) (x).begin(),(x).end()

typedef long long ll;
typedef unsigned long long ull;

const int INF = 1e9;

int main(){
   char s[13];
   rep(i,4)cin >> s[i];
   s[4] = ' ';
   for(int i=5;i<13;i++)cin >> s[i];
   cout << s << endl;
   return 0;
}
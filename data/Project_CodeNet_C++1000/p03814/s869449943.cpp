/* Note:
Check constants at the beginning of the code.
    N is set to 4e5 but be careful in problems with large constant factor.
    Setting N in every problem is more effective.
Check corner cases.
    N = 1
No def int long long for now.
Add something here.

*/
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
typedef long double ld;

int mod = 1000000007;
ll dp[100005];
const ll INF = 1e18;

ll gcd(long long a,long long b){
  if(b == 0)
    return a;
  else return gcd(b,a%b);
}

bool sortbyval(const pair<string, int> &a,
               const pair<string, int> &b){
    return (a.second < b.second);
}

int main(){

string s;
 cin>>s;

 int start=0,ends=-2;

 for(int i=0;i<s.length();i++){

    if(s[i] == 'A'){
        start = i;
        break; }
 }

 for(int i=0;i<s.length();i++){

    if(s[i] == 'Z'){
        if(i>ends)
            ends = i; }
 }


 //ends = ends+1;

 cout<<ends-start+1<<endl;

return 0;
}

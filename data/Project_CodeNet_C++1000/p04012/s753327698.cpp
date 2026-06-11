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

int mod = 1000000007;
ll dp[100005];;

ll gcd(long long a,long long b){

  if(b == 0)
    return a;
  else return gcd(b,a%b);
}


bool sortByVal(const pair<string, int> &a,
               const pair<string, int> &b)
{
    return (a.second < b.second);
}

int main(){

 string s;
 cin>>s;
 map<char,int>mp;

 for(int i=0;i<s.length();i++){
    mp[s[i]]++;
 }

 for(map<char,int>::iterator it=mp.begin();it!= mp.end();it++){

  if(it->second % 2 != 0){
  cout<<"No"<<endl;
  return 0; }
 }

 cout<<"Yes"<<endl;

return 0;
}

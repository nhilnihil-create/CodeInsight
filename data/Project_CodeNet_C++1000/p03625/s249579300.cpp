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

 int n; cin>>n;
 map<long long,long long>mp;

 for(int i=0;i<n;i++){

    long long a;
    cin>>a;
    mp[a]++;
 }

 vector<long long>Q;

 for(map<long long,long long>::iterator it = mp.begin();it!= mp.end();it++)
 {
   if(it->second >= 4){
    Q.push_back(it->first);
    Q.push_back(it->first);
   }
    else if(it->second >= 2)
        Q.push_back(it->first);
 }

 sort(Q.begin(),Q.end(),greater<long long>());

 if(Q.size() < 2)
    cout<<"0"<<endl;
 else
   cout<<Q[0]*Q[1]<<endl;



 return 0;
}


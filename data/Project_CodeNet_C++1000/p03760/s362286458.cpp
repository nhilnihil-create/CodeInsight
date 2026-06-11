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
#define MAX 10000

using namespace std;
typedef long long ll;

int mod = 1000000007;
ll dp[100005];;

ll gcd(long long a,long long b){

  if(b == 0)
    return a;
  else return gcd(b,a%b);
}

bool compare(pair<int,int>p1, pair<int,int>p2){

  return p1.second > p2.second;
 }
/*
 int main(){

  long long n,cnt=0;
  cin>>n;

  long long a[n];
  bool tells[n] = {false};

  for(int i=0;i<n;i++)
    cin>>a[i];

  for(int i=0;i<n-1;i++){
   for(int j=i+1;j<n;j++){

     long long sum = a[i]+a[j];
     if(sum %2 == 0){
        if(tells[i] == false && tells[j] == false){
          tells[i] = true; tells[j] = true;
        cnt++;
         break; }
     }
   }
  }

  cout<<cnt<<endl;

 return 0;
 }
*/

int main(){

 string a,b;
 string maxi,mini;
 int pos=-1;

 cin>>a>>b;

  if(a.length() > b.length()){
     maxi = a;
     mini = b; }
  else  if(b.length() > a.length()){
      maxi = b;
    mini = a; }
  else if(a.length() == b.length()){
      maxi = a;
      mini = b; }

 for(int i=0;i<mini.length();i++)
 {
    cout<<maxi[i];
    cout<<mini[i];
    pos = i;
 }

 for(int j=mini.length();j<maxi.length();j++)
    cout<<maxi[j];

 cout<<endl;

return 0;
}

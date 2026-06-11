#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>


int main(){
  ll N, A, B; cin >> N >> A >> B;
  ll retval;
  if (A>B) retval = 0;
  else if (N==1 && A==B) retval = 1;
  else if (N==1 && A!=B) retval = 0;
  else {
    retval = B*(N-2) - A*(N-2) +1;
  } 
  cout << retval << endl;


  // cout << fixed << setprecision(10);
  
  return 0;
}


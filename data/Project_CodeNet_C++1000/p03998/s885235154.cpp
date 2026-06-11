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
  string a[3]; rep(i,3) cin >> a[i];

  int turn = 0;
  while (1){
    if (a[turn].size()==0) break;


    char c = a[turn][0];
    a[turn].erase(0,1);
    if (c=='a') turn = 0;
    else if (c=='b') turn = 1;
    else turn = 2;
    
    
  }
  
  string ABC = "ABC";
  cout << ABC[turn] << endl;
  

  // cout << fixed << setprecision(10);
  
  return 0;
}


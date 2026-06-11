#include <iostream>
//#include <math.h>
#include <set>
#include<iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <queue>
#define INF 1e9+7
#define rep(i,n) for(int i=0;i<n;i++)
#define NO cout<<"NO"<<endl;
#define YES cout << "YES"<<endl;
#define No cout << "No"<<endl;
#define Yes cout << "Yes"<<endl;
#define all(a) a.begin(),a.end()
#define P pair<int,int>
#define space ' '
#define pll pair<ll,ll>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

//(int)'a'は97 (int)'A'は65 (int)'1'は49
//おまじない

const int maxn = 100000;

int main(){

  int n;
  ll ans = 0;
  ll mod = INF;
  int pre = 0;
  string s,t;

  cin >> n;
  cin >> s>>t;

  rep(i,n){
    if(i==0){
      if(s[i]==t[i]){
        ans = 3;
        pre = 0;
      }else{
        ans = 6;
        pre = 1;
        i++;
      }
    }else{
      if(s[i]==t[i]){   //縦に揃っている
        if(pre==0){   //一つ前は縦に揃っていた
          ans = ans * (ll)2 % mod;
        }else if(pre==1){   //一つ前は横が揃っていた
          ans = ans;
        }
        pre = 0;
      }else{    //横に揃っている
        if(pre==0){   //一つ前は縦に揃っていた
          ans = ans * (ll)2 % mod;
        }else if(pre==1){   //一つ前は横に揃っていた
          ans = ans * (ll)3 % mod;
        }
        i++;
        pre = 1;
      }
    }
  }

  cout << ans << endl;

  return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define erep(i,n) for(int i = 0;i<=n;i++)
#define rep1(i,n) for(int i = 1;i<n;i++)
#define erep1(i,n) for(int i = 1;i<=n;i++)
typedef long long ll;
#define vint vector<int>
#define vstring vector<string>
#define vll vector<ll>
#define vbool vector<bool>
#define INF 100000000

int main(){
  int n;
  cin >> n;
  ll left = 1,right = 1;
  rep(i,n){
    ll a,b;
    ll key = 0;
    cin >> a >> b;
    if(left % a == 0 && right % b == 0){
      //cout << "a" << endl;
      key = max(left/a,right/b);
    }
    else if(left % a == 0){
      //cout << "b" << endl;
      key = max(left/a,right/b+1);
    }
    else if(right % b == 0){
      //cout << "c" << endl;
      key = max(left/a+1,right/b);
    }
    else{
      //cout << "d" << endl;
      key = max(left/a+1,right/b+1);
    }
    left = a*key;
    right = b*key;
    //cout << key << endl;
    //cout << left << " " << right << endl;
  }
  cout << left + right << endl;
}
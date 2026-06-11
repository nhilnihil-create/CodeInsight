#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
int INF = 100100101;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  int a[4];
  rep(i,4){
    a[i] = 0;
  }  
  rep(i,s.length()){
    if(s[i] == 'E'){
      a[0]++;
    }
    if(s[i] == 'W'){
      a[1]++;
    }
    if(s[i] == 'S'){
      a[2]++;
    }
    if(s[i] == 'N'){
      a[3]++;
    }
  }
  if(a[0] > 0 && a[1] == 0){
	cout << "No" << endl;
    return 0;
  }
  if(a[0] == 0 && a[1] > 0){
	cout << "No" << endl;
    return 0;
  }
  if(a[2] > 0 && a[3] == 0){
	cout << "No" << endl;
    return 0;
  }
  if(a[2] == 0 && a[3] > 0){
	cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  return 0;
}
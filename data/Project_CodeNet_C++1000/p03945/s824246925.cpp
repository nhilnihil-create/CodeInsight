#include<iostream>
#include<cmath>
#include<numeric>
#include<functional>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<n;i++)
#define ll long long
#define INF 2147483647
using namespace std;
using Graph=vector<vector<int>>;

int main(){
  int ans=0;
  string s;
  cin>>s;
  for(int i=0;i<s.length()-1;i++){
    if(s[i]!=s[i+1]){
      ans++;
    }
  }
  cout<<ans;
}

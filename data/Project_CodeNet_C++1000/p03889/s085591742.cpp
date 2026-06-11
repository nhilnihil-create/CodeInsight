#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<math.h>
#include<string>
#include<string.h>
#include<stack>
#include<queue>
#include<vector>
#include<utility>
#include<set>
#include<map>
#include<stdlib.h>
#include<iomanip>

using namespace std;

#define ll long long
#define ld long double
#define EPS 0.0000000001
#define INF 1e9
#define MOD 1000000007
#define rep(i,n) for(i=0;i<n;i++)
#define loop(i,a,n) for(i=a;i<n;i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)

typedef vector<int> vi;
typedef pair<int,int> pii;

int main(void) {
  int i,j;
  string s1,s2;
  cin>>s1;
  s2=s1;
  reverse(all(s1));
  rep(i,s1.size())
    if(s1[i]=='b')s1[i]='d';
    else if(s1[i]=='d')s1[i]='b';
    else if(s1[i]=='p')s1[i]='q';
    else if(s1[i]=='q')s1[i]='p';
  if(s1==s2)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
}

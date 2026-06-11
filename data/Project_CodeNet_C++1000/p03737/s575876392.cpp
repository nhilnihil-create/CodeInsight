#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;
int main()
{
  string s1,s2,s3;
  cin>>s1>>s2>>s3;

  cout<<char('A'+(s1[0]-'a'))<<char('A'+(s2[0]-'a'))<<char('A'+(s3[0]-'a'))<<endl;
  return 0;
}

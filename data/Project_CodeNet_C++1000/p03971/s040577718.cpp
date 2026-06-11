#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1000000000; // 10^9

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll N,A,B,cnt=0,p=0;
  cin>>N>>A>>B;

  char s[N];
  cin>>s;

  for(int i=0; i<N; i++) {
    if(s[i]=='c') {
      cout<<"No"<<'\n';
    }
    else if(s[i]=='a') {
      if(cnt<(A+B)) {
        cnt++;
        cout<<"Yes" << '\n';
      }
      else {
        cout<<"No" << '\n';
      }
    }
    else if(s[i]=='b') {
      if(cnt<A+B && p+1<=B) {
        cnt++;
        p++;  
        cout<<"Yes"<<'\n';
      }
      else {
        cout<<"No"<<'\n';
      }
    }
  }

  return 0;
}


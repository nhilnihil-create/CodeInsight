#include <bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


#define INF 1000000000000

signed main()
 {
string s;
cin>>s;
rep(i,s.size()){
  if(i%2==0){
    cout<<s.at(i);
  }
}
}

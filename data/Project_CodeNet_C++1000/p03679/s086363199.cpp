#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long X=1000000000+7;
const string d="dream";
const string e="erase";

int main() {
  long x,a,b;
  cin>>x>>a>>b;
  if(a>=b) cout<<"delicious"<<endl;
  else if(a+x>=b) cout<<"safe"<<endl;
  else cout<<"dangerous"<<endl;
}

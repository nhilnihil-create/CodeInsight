#include<bits/stdc++.h>
using namespace std;
constexpr int64_t mod=1e9+7;

std::vector<string> v={"SS","SW","WS","WW"};
std::map<string, char> mp_o={
  {"WW",'S'},
  {"WS",'W'},
  {"SS",'S'},
  {"SW",'W'},
},mp_x={
  {"WW",'W'},
  {"WS",'S'},
  {"SS",'W'},
  {"SW",'S'},
};
int main()
{
  int n;
  cin>>n;
  string s;
  cin>>s;
  vector<char> vec(n+1);
  
  for(auto&& e: v) {
    vec[0]=e[0];
    vec[1]=e[1];
    for (int i = 1; i < n; ++i)
    {
      if(s[i]=='o'){
        string tmp={vec[i-1]};
        tmp+=vec[i];
        vec[i+1]=mp_o[tmp];
      }
      else{
        string tmp={vec[i-1]};
        tmp+=vec[i];
        vec[i+1]=mp_x[tmp];
      }
    }
    if(vec[n]==vec[0]){
      string tmp={vec[n-1]};
      tmp+=vec[0];
      char judge;
      if(s[0]=='o') judge=mp_o[tmp];
      else judge=mp_x[tmp];
      if(judge==vec[1]) {
        for (int i = 0; i < n; ++i)
        {
          cout<<vec[i];
        }
        return 0;
      }
    }
  }
  cout<<-1;
}
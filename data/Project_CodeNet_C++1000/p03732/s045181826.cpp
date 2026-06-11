#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
  int n,w,w1,ww,vv,tw,tv,t,i,j,k,res=0;
  vector<int> v[4],s[4];
  cin >> n >> w;
  cin >> w1 >> vv;
  v[0].push_back(vv);
  for(i=1;i<n;i++){
    cin >> ww >> vv;
    v[ww-w1].push_back(vv);
  }
  for(i=0;i<4;i++){
    sort(v[i].begin(),v[i].end(),greater<int>());
    s[i].push_back(0);
    for(j=0;j<(int)v[i].size();j++)
      s[i].push_back(s[i][j]+v[i][j]);
  }
  for(i=0;i<=(int)v[0].size();i++){
    tw=w1*i;
    if(tw>w) break;
    for(j=0;j<=(int)v[1].size();j++){
      tw=w1*i+(w1+1)*j;
      if(tw>w) break;
      for(k=0;k<=(int)v[2].size();k++){
        tw=w1*i+(w1+1)*j+(w1+2)*k;
        if(tw>w) break;
        t=min((w-tw)/(w1+3),(int)v[3].size());
        tv=s[0][i]+s[1][j]+s[2][k]+s[3][t];
        res=max(res,tv);
      }
    }
  }
  cout << res << endl;
  return 0;
}
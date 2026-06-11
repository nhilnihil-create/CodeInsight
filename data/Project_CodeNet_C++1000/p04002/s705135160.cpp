#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
#include<fstream>
#include<iostream>
using namespace std;

int main(){
  long h,w,num[10]={},a,b;
  int n,cnt=0;
  vector<pair<long,long>> p;
  scanf("%ld %ld %d",&h,&w,&n);
  for(int i=0;i<n;i++){
    scanf("%ld %ld",&a,&b);
    for(long j=max((long)1,a-2);j<=min(a,h-2);j++)
      for(long k=max((long)1,b-2);k<=min(b,w-2);k++)
        p.push_back(make_pair(j,k));
  }
  a=b=0;
  sort(p.begin(),p.end());
  p.push_back(make_pair(h+1,w+1));
  for(int i=0;i<p.size();i++){
    if(a==p[i].first&&b==p[i].second)
      cnt++;
    else{
      num[cnt]++;
      cnt=1;
      a=p[i].first;
      b=p[i].second;
    }
  }
  num[0]=(h-2)*(w-2);
  for(int i=1;i<=9;i++)
    num[0]-=num[i];

  //ofstream fout("out2.txt");
  for(int i=0;i<10;i++)
    cout << num[i] << endl;
}

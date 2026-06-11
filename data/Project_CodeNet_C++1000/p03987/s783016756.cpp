#include<bits/stdc++.h>

using namespace std;

set<int> mn,mx;

int data[200005];
unsigned long long ans=0;

int main()
{
  int n,i;

  scanf("%d",&n);
  for(int c=0;c<n;c++)
  {
    scanf("%d",&i);
    data[i]=c;
  }
  for(int c=1;c<=n;c++)
  {
    set<int>::iterator it;
    unsigned long long mncount,mxcount;

    it=mn.upper_bound(-data[c]);
    if (it==mn.end())mncount=data[c];
    else mncount=data[c]-(-(*it))-1;
    it=mx.upper_bound(data[c]);
    if (it==mx.end())mxcount=(n-1)-data[c];
    else mxcount=(*it)-data[c]-1;

    ans+=((mncount*mxcount)+(mncount+mxcount+1))*c;
    mn.insert(-data[c]);
    mx.insert(data[c]);
  }
  printf("%llu\n",ans);
}

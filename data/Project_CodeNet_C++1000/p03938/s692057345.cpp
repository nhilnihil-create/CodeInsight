#include<bits/stdc++.h>

using namespace std;

vector<int> ans1,ans2;

int main()
{
  int n,i;

  scanf("%d",&n);
  ans1.resize(n);
  ans2.resize(n);
  ans1[0]=1;
  ans2[0]=1+(20000*(n-1));
  for(int c=1;c<n;c++)
  ans1[c]=ans1[c-1]+20000,ans2[c]=ans2[c-1]-20000;
  for(int c=0;c<n;c++)
  {
    scanf("%d",&i);
    ans1[i-1]+=c;
  }
  printf("%d",ans1[0]);
  for(int c=1;c<n;c++)
  printf(" %d",ans1[c]);
  printf("\n");
  printf("%d",ans2[0]);
  for(int c=1;c<n;c++)
  printf(" %d",ans2[c]);
  printf("\n");
}

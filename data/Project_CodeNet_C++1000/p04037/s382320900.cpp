#include<bits/stdc++.h>
  using namespace std;
const int N=100000;
int a[N+5],n,x,y;
inline void into(){
  scanf("%d",&n);
  for (int i=1;i<=n;i++)
    scanf("%d",&a[i]);
}
bool cmp(int a,int b){
  return a>b;
}
inline void work(){
  sort(a+1,a+1+n,cmp);
  for (;x<=n&&x+1<=a[x+1];x++);
  for (y=x;y+1<=n&&a[y+1]==x;y++);
}
inline void outo(){
  if (a[x]-x&1||y-x&1) printf("First\n");
  else printf("Second\n");
}
int main(){
  into();
  work();
  outo();
  return 0;
}
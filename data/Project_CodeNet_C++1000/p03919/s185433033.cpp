#include<cstdio>
#include<cstring>
using namespace std;
int main(){
  int h,w;
  scanf("%d %d",&h,&w);
  char s[10];
  for(int i=0;i<h;i++)
    for(int j=0;j<w;j++){
      scanf("%s",s);
      if(strcmp(s,"snuke")==0)
        printf("%c%d\n",j+'A',i+1);
    }
}
#include <stdio.h>

int main(){

int i,j,H,W,n,m;
char p[6];

scanf("%d %d",&H,&W);
for(i=0;i<H;i++){
  for(j=0;j<W;j++){
      scanf("%s",p);
 if(p[0]=='s'&&p[1]=='n'&&p[2]=='u'&&p[3]=='k'&&p[4]=='e'){
          n=j;
          m=i;
        }

  }
}

printf("%c%d\n",n+65,m+1);

return 0;
}
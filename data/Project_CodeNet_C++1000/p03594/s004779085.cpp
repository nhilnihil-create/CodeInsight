#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int h, w, d;
int col[500][500];
int seed[4][4] = { {1, 0, 2, 0},
                   {0, 4, 0, 3},
                   {2, 0, 1, 0},
                   {0, 3, 0, 4} };
void RYGB(int n){
  char c;
  switch (n){
  case 0: c = 'O'; break;
  case 1: c = 'R'; break;
  case 2: c = 'Y'; break;
  case 3: c = 'G'; break;
  case 4: c = 'B'; break;
  }
  printf("%c",c);
}

int main(void) {
  scanf("%d %d %d",&h, &w, &d);

  if(d%2 == 1) for(int i=0;i<h;i++) for(int j=0;j<w;j++) col[i][j] = (i+j)%2 ? 2 : 3;
  else{
    int ifin = (ceil(1.0*h/d))*2 + 1, jfin = ceil(2.0*w/d);
    int halfd = d/2, hc, wc, hcs, wcs;
    int seedi, seedj;
    for(int i=0;i<ifin;i++) for(int j=-i%2;j<jfin;j+=2){
        seedi = i%4;
        seedj = (j+4)%4;
        hc = i * halfd;
        wc = j * halfd;
        for(int m=0;m<2;m++){
          wc += m;
          for(int k=0;k<halfd;k++) for(int l=0;l<halfd;l++){
              hcs = hc +k -l;
              wcs = wc +k +l;
              if(hcs>=0 && hcs<h && wcs>=0 && wcs<w) col[hcs][wcs] = seed[seedi][seedj];
            }
        }
      }   
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      RYGB(col[i][j]);
    }
    printf("\n");
  }
  return 0;
}
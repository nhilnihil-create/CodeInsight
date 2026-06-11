#include <bits/stdc++.h>
using namespace std;

long int Min(long int a, long int b);
long int Max(long int a, long int b);

long int Min(long int a, long int b){
  return a > b ? b : a;     
}

long int Max(long int a, long int b){
  return a < b ? b : a;
}

int main() {
  long int w,h, wh, div3;
  long int max0, min0, max1, min1, minmax0=0, minmax1=0;
  long int best0=0x7fffffffffffffff, best1=0x7fffffffffffffff;
  long int p1,p2v,p3v,p2h,p3h;
  
  // 画枠入力
  cin >> h >> w;
  
  wh = w*h;
  
  //最初にhorizonatal方向に切る
  for(int i=1; i<h; i++){
    p1 =  w*i;
    p2h = w*(((h-i)+1)/2);
    p3h = w*(((h-i))/2);
    
    p2v = (w/2)*(h-i);
    p3v = ((w+1)/2)*(h-i);
    
    min0 = Min(Min(p2h, p3h), p1);
    max0 = Max(Max(p2h, p3h), p1);
    
    minmax0 = max0-min0;
    
    min0 = Min(Min(p2v, p3v), p1);
    max0 = Max(Max(p2v, p3v), p1);
    
    minmax0 = Min(max0 - min0, minmax0);
    
    //printf("%d, %d, %d, %d, %d, %d\n",p1 , p2h, p3h, p2v, p3v, minmax0);
    if(minmax0 <= best0) best0 = minmax0; 
  }

  //vertical方向
  for(int i=2; i<w; i++){
    p1 =  h*i;
    p2h = (w-i)*((h+1)/2);
    p3h = (w-i)*(h/2);
    
    p2v = ((w-i)/2)*h;
    p3v = ((w-i+1)/2)*h;
    
    min0 = Min(Min(p2h, p3h), p1);
    max0 = Max(Max(p2h, p3h), p1);
    
    minmax0 = max0-min0;
    
    min0 = Min(Min(p2v, p3v), p1);
    max0 = Max(Max(p2v, p3v), p1);
    
    minmax1 = Min(max0 - min0, minmax0);
    
    //printf("ver:%d, %d, %d, %d, %d, %d\n",p1 , p2h, p3h, p2v, p3v, minmax1);
    if(minmax1 <= best1) best1 = minmax1; 
  }
  
   cout << min(best0,best1) << endl;
}
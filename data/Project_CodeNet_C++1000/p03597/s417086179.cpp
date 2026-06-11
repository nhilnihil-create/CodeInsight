/* kadai2_2
   reo012 */

#include <stdio.h>

int main(void){
  int n, a;
  // 二つの整数(一列のマス数、白マス数)n,aを受け取り
  scanf("%d", &n);
  scanf("%d", &a);
  // 黒く塗るマス数を計算し、出力
  printf("%d\n", n*n-a);
  
  return 0;
}
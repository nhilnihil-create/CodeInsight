#include<stdio.h>
int main(){
    int i, j, tmp;
 
  /* 数値を格納する配列 */
    int l[200];
 
  /* 数値の総数を入力 */
    int n;
    scanf("%d", &n);
 
  /* 配列に格納する数値を入力 */
    for (i=0; i<2*n; ++i)
        scanf("%d", &l[i]);
 
  /* 数値を昇順にソート */
    for (i=0; i<2*n; ++i) {
        for (j=i+1; j<2*n; ++j) {
            if (l[i] > l[j]) {
                tmp =  l[i];
                l[i] = l[j];
                l[j] = tmp;
            }
        }
    }
    int sum=0;
    for(int i=0;i<2*n;i=i+2){
        sum+=l[i];
    }
    printf("%d\n",sum);
    return 0;
}
     
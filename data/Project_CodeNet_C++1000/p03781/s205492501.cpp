#include <iostream> //调用lower_bound 
const int N = 44721; 
using namespace std;
int sum[N];    //全局变量清0 
int main()
{
      int x,i; 
    scanf("%d", &x);
    for (int i = 1; i <= N; i++)
        sum[i] = sum[i-1] + i;
        
        
    i=lower_bound(sum,sum+N,x)-sum;//函数用法熟练 
    printf("%d", i);
    return 0;
}
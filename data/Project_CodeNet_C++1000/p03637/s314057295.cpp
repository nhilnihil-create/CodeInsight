#include <cstdio>
//找规律 不用真正模拟计算，只要找出数字个数的规律
int main(void)
{
    int a1count = 0, a2count = 0, a4count = 0;
    int i, N, x;
    scanf("%d", &N);
    while (N--)
    {
        scanf("%d", &x);
        if (x % 4 == 0)
            a4count++; //是4的倍数，可以放在任何数旁边构成幸运数列
        else if (x % 2 == 0)
            a2count++; //不是4但是2的倍数，要么放在a4旁边，要么放在a2 自己旁边
        else
            a1count++;//不是2的倍数，也不是4的倍数，就是其他数字，必须放在a4旁边
    }
    //先让a1与a4交替出现，a1的个数只能比a4的个数最多多一个，最好小于a4的个数
    if (a2count > 0 && a1count <= a4count) //类似 a1,a4,a1,a4,a2,a2,a2...
        printf("Yes\n");
    else if (a2count == 0 && a1count <= a4count + 1)//类似 a1,a4,a1 
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
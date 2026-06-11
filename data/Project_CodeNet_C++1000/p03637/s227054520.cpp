#include<iostream>
//#include<algorithm>
using namespace std;
int main()
{
    int n, num_2 = 0, num_4 = 0, num_not24 = 0, tmp;
    bool is_luck;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &tmp);
        if(tmp % 4 == 0)
            num_4++;
        else if(tmp % 2 == 0)
            num_2++;
        else
            num_not24++;
    }
    if(num_2 != 0)
    {
        if(num_4 >= num_not24)
            is_luck = true;
        else
            is_luck = false;
    }
    else
    {
        if(num_4 >= num_not24 - 1)
            is_luck = true;
        else
            is_luck = false;
    }
    if(is_luck)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}

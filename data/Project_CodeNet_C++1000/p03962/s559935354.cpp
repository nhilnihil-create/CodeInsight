#include <iostream>

using namespace std;

int main()
{
    int a[3];
    int sum=0;
    for(int i=0;i<3;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<3;i++)
        for(int y=0;y<i;y++)
        if(a[i]==a[y])
        sum++;
    if(sum==3)
        sum--;
    cout<<(3-sum);

    return 0;
}

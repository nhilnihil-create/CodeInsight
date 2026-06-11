#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n,count = 0,ans = -1,flag;
    cin>>n;
    for(int i = 1;i<=n;i++)
    {
       count = 0;
       int temp = i;
        while(temp%2 == 0 && temp != 0)
        {
            count++;
            temp = temp/2;
            //cout<<"fU\n";
        }
        if(count > ans)
            flag = i;
        ans = max(count,ans);
    }
    cout<<flag<<endl;
    return 0;
}
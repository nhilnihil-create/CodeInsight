#include<iostream>

using namespace std;

int main()
{
    int arr1[7] = {1,3,5,7,8,10,12};
    int arr2[4] = {4,6,9,11};
    int arr3[1] = {2};
    int a, b;
    cin>>a>>b;
    int p = 0,q = 0;
    if(a != 2)
    {
        for(int i = 0; i < 4; i++)
        {
            if(a == arr2[i])
            {
                p = 1;
                break;
            }
        }
    }
    else p = 2;
    if(b != 2)
    {
        for(int i = 0; i < 4; i++)
        {
            if(b == arr2[i])
            {
                q = 1;
                break;
            }
        }
    }
    else q = 2;
    if(p == q) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}

#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cin>>n;
    long long int max=0,ms=0,tot_player;
    long long int arr[n][2];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<2;j++)
        {
            cin>>arr[i][j];
        }
        if(arr[i][0]>max)
        {
            max=arr[i][0];
            ms=arr[i][1];
        }
    }
    tot_player=max;
    while(ms--)
    {
        tot_player++;
    }

    cout<<tot_player<<endl;
    return 0;
}
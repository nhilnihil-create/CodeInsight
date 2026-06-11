#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a ,x=0,arr[100];
    char s;
    cin>>a;
    for(int i=0;i<a;i++)
    {
     cin>> s;
        if(s=='D')
        {
            x-=1;
        arr[i]=x;
        }

        else if(s=='I')
         {
             x+=1;
            arr[i]=x;
         }
    }
    sort(arr,arr + a , greater<int>());
     if(arr[0]>0)
     cout<<arr[0];
     else
        cout<<0;
	return 0;
	}




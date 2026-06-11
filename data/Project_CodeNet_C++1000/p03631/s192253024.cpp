#include <bits/stdc++.h>
using namespace std;
int i_max(int arr[],int n){
    int MAX=arr[0];
   int  i1=0,i2=0;
    for (int i= 0;i<n;i++)
    {
        if (arr[i]>MAX)
        {
            MAX =arr[i];
            i1=i;
            i2=i;
        }
        else if (arr[i]==MAX)
        {
            i2=i;
        }
   }
    return max(i1,i2);
}
int i_min(long long int arr[],int n,int& i1,int& i2){
    long long int min=arr[0];
    i1=0;
    i2=0;
     for (int i= 0;i<n;i++)
     {
         if (arr[i]<min)
         {
             min =arr[i];
             i1=i;
             i2=i;
         }
         else if (arr[i]==min)
         {
             i2=i;
         }
    }
     return max(i1,i2);
}

int main (){
    // two magical lines to speed up IO
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >>n;
    int a[3]={0};
    a[2]=n%10;
    n/=10;
    a[1]=n%10;
    n/=10;
    a[0]=n%10;
    if (a[0]==a[2])
        cout << "Yes\n";
    else
        cout << "No\n";
    
}

  

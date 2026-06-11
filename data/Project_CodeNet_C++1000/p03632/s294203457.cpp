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
    int a,b,c,d;
    cin >>a>>b>>c>>d;
    if (a<=c){
        if (d<=b){
            cout <<(d-c);
        }
        else if (b<d && b>c)
        {
            cout <<(b-c);
        }
        else
            cout <<0;
    }

if (a>c){
        if (d>=b){
            cout <<(b-a);
        }
        else if (b>d && d>a)
        {
            cout <<(d-a);
        }
        else
            cout <<0;
    }
    cout <<endl;
}
 // a c d b
            //a c b d
            // a b c d
  

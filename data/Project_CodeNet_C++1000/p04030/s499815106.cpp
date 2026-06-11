#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    string x;
    cin>>x;
    string a;
    int count=0;
    for(int i=0;i<x.length();i++){
        if (x[i]=='B'){
            if (count>0)
                count--;
        }
        else{
            a[count]=x[i];
            count++;
        }
    }
    //printf("%d\n",count);
   // printf("%c\n",a[0]);
    for(int i=0;i<count;i++){
       printf("%c",a[i]);
    }
}
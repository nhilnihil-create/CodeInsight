#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<iterator>
#include<math.h>
#include<cstring>
using namespace std;
void lets_play()

{
    char s[1000][1000],temp[1000];
    int i,j,n,l;
    cin>>n>>l;
   for(i=0;i<n;i++)
   {
            cin>>s[i];
   }

    for(i=0;i<n;i++)
   {
       for(j=i+1;j<n;j++)
          {
              if(strcmp(s[i],s[j])>0)
              {
                  strcpy(temp,s[i]);
                  strcpy(s[i],s[j]);
                  strcpy(s[j],temp);
              }
          }
   }

   for(i=0;i<n;i++)
   {
            cout<<s[i];
   }
}

int main()
{
        lets_play();

}

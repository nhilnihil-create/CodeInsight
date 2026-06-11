#include<bits/stdc++.h>

using namespace std;

const int maxi=1e6;

long long a[maxi],b[maxi];

int size(long long x, long long y)
{
    int ans=0,ans1=0;
    while(x>0)
    {
        x/=10;
        ans++;
    }

    while(y>0)
    {
        y/=10;
        ans1++;
    }

    if (ans!=ans1) return 1; else return 0;
}

int main()
{


  b[0]=1;
  int cnt=0;

    for (int i=1;i<=10;i++)
        {
            a[i]=a[i-1]*10+9;
            b[i]=b[i-1]*10;
        }

   long long cur=0;
   long long ask=0;
   long long ser=1;
   char ch;

    for (int k=1;k<=10;k++)
    {

        long long l=0;
        long long r=9;

        while(r-l>=2){
         ask=(cur*10+(l+r+1)/2)*b[10-ser]+a[10-ser];

         printf("? %lld\n",ask);
         cnt++;
         fflush(stdout);
         scanf(" %c",&ch);

         if (ch=='Y')
           r=(l+r+1)/2;
         else
            l=(l+r+1)/2 +1;

        }

        if (ser==1 && l==0) l++;

        int rez=r;

        for (int i=l;i<=r;i++){
        ask=(cur*10+i)*b[10-ser]+a[10-ser];

         printf("? %lld\n",ask);
         cnt++;
         fflush(stdout);
         scanf(" %c",&ch);
         if (ch=='Y') { rez=i; break;}
        }

         cur=cur*10+rez;
         ser++;
    }

     int tip=0;

    while(1==1)
    {
        if (cur%10!=0) break;

        cur+=1;

        printf("? %lld\n",cur);
        fflush(stdout);
        cnt++;
         scanf(" %c",&ch);

         if (ch=='N'){
          tip=1;
          break;
         }
          cur/=10;
    }


   if (tip==1) { printf("! %lld\n",(cur-1)*10); fflush(stdout); } else {

   cur*=10;
   cur--;
   printf("? %lld\n",cur);
   cnt++;
   fflush(stdout);

   scanf(" %c",&ch);
   if (ch=='N' && cur==9) printf("! %lld\n",10); else
    if (cur==9) printf("! %lld\n",1); else
   if (ch=='N') {printf("! %lld\n",(cur+1)/10);} else
   printf("! %lld\n",cur+1);
   }
   fflush(stdout);
   //cout<<cnt<<"\n";
   return 0;
}

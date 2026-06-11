#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
       long long N;
       long long Sum_t[200000]={0};

       cin>>N;
       cin>>Sum_t[0];
       for(int i=1;i<N;i++)
       {
             cin>>Sum_t[i];
             Sum_t[i]=Sum_t[i-1]+Sum_t[i];
        }

       long long min=abs(Sum_t[N-1]-2*Sum_t[0]);
        for(int i=1;i<N-1;i++)
        {
                long long temp=abs(Sum_t[N-1]-2*Sum_t[i]);
                if(temp<min) min=temp;
         }
   
        cout<<min;
        return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
   map <int,int> freq;
   for(int i = 0; i < 3;i++)
   {
     int value = 0;
     cin>>value;
     freq[value]++;
   }

      if(freq[5] == 2 && freq[7] == 1)
        cout<<"YES"<<endl;
      else
        cout<<"NO"<<endl;

}

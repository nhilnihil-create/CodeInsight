#include <iostream>
#include<map>
#include<vector>
using namespace std;
void factorize(int a,vector<int> vec,map<int,int> &mp)
{
    int k=vec[0];
    int i=0;
    int count=0;
    while(a&&i<vec.size())
    {
        if(a%k==0)
       {
       a=a/k;
       count++;
       }
        else {
            mp[k]+=count;
        i++;
        k=vec[i];
        count=0;
        }
    }
   
}

int main() {
   int n;
   cin>>n;
   int arr[1001];
   for(int i=0;i<1001;i++)
   arr[i]=1;
   for(int i=2;i<1001;i++)
   {
       if(arr[i])
       {
           for(int j=i*i;j<1001;j+=i)
           arr[j]=0;
       }
   }
   vector<int> vec;
  // map<int,int> mp;
   for(int i=2;i<1001;i++)
   {
       if(arr[i])
       vec.push_back(i);
   }
   map<int,int> mp;
   for(int i=2;i<=n;i++)
   {
       factorize(i,vec,mp);
   }
   long long int res=1;
   for(auto it=mp.begin();it!=mp.end();it++)
   {
      res=(res*(it->second+1))%1000000007;
   }
   cout<<res%1000000007<<endl;
}

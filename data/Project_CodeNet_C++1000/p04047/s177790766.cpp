#include<bits/stdc++.h>
using namespace std;
int main()
{
        int n;cin>>n;
        vector<int>nums;
        for(int i=0;i<2*n;i++)
        {
                int x;cin>>x;
                nums.push_back(x);
        }
        sort(nums.begin(),nums.end());
        long sum=0;
        //if(n>)
        for(int i=0;i<nums.size();i=i+2)
        {
                sum=sum+nums[i];
        }
        cout<<sum<<endl;
}
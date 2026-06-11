#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b,sum=0,sum1=0,d,e;
    cin>>a;
    vector<long long>tap;
    vector<long long>dp;
    for(int i=0;i<a-1;i++)
    {
        cin>>b;
        tap.push_back(b);
        sum=sum+b;
        //reverse(tap.begin(),tap.end());


    }
    cin>>b;
    sum1=b;
    d=abs(sum-sum1);
    //cout<<sum<<" "<<sum1<<" "<<d<<endl;
    dp.push_back(d);

    for(int i=a-2;i>=1;i--)
    {



        //e=tap[i];
        sum-=tap[i];
        sum1+=tap[i];
        d=abs(sum-sum1);
        dp.push_back(d);


        //reverse(tap.begin(),tap.end());


    }
    

    sort(dp.begin(),dp.end());
    cout<<dp[0];

}


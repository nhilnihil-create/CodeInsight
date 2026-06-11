#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,i,sum = -100,m;
    map<long long int,long long int>mp;

    vector<long long int>v;
    cin>>n;
    for(i = 0; i < n; i++)
    {
        cin>>m;
      if(mp[m]==0)
        v.push_back(m);

        mp[m]++;


    }
    sort(v.begin(),v.end());
    for(i = 0; i < v.size(); i++)
    {

        if(mp[v[i]]>=2)
        {
            for(int j = v.size()-1; j > i; j--)
            {
                if(mp[v[j]]>=2)
                {

                    if(v[i]*v[j]>sum)
                        sum = v[i]*v[j];
                    break;
                }

            }
        }

    }
    for(i = v.size()-1; i >= 0; i--)
    {

        if(mp[v[i]]>=4 && v[i]*v[i]>sum)
        {
            sum = v[i]*v[i];
            break;
        }

    }

    if(sum<0)
        sum = 0;
    cout<<sum<<endl;
    return 0;
}

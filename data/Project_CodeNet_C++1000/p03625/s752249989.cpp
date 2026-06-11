#include<bits/stdc++.h>
#define cy cout << "YES" << endl;
#define cn cout << "NO" << endl;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int main()
{

    long long a,b,c,d,e;
    cin >> a;
     map<long long,long long>mp;
    vector<long long>vec;
    while(a--)
    {
        cin >> b;
        mp[b]++;
    }

    for(auto it=mp.begin();it!=mp.end();it++){
        if(it->second>=4)
        {
            vec.push_back(it->first);
            vec.push_back(it->first);
        }
        if(it->second>=2)

        {
            vec.push_back(it->first);
        }

    }
    sort(vec.begin(),vec.end());
    if(vec.size()>1)
    {
        long long x=vec[vec.size()-1]*vec[vec.size()-2];
        cout << x << endl;

    }
    else{
        cout << 0 << endl;
    }


}
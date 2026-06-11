#include<set>
#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include <utility>
#include<algorithm>

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main()
{
    fast;



    long long a,b,c,d,e,f,target,i,j;
    long long sum=0;
    cin >> a >> target;

    map<long long,long long>mp;
    vector<long long>vec;
    while(a--)
    {
        cin >> b;
        vec.push_back(b);




    }
    vector<pair<long long,long long>>vec2;
    for(i=1;i<vec.size();i++)
    {
        vec2.push_back({vec[i]+vec[i-1],i});
    }
    sort(vec2.begin(),vec2.end());
    reverse(vec2.begin(),vec2.end());
    e=vec2[0].first;
    f=vec2[0].second;
    if(e>=target)
    {
        //cout << "f  ==  " << f << endl;
        cout << "Possible" << endl;
        for(i=1;i<f;i++)
            cout << i << endl;
        for(i=vec.size()-1;i>=f+1;i--)
        {
            cout << i << endl;
        }
        cout << f << endl;

    }
    else{
        cout << "Impossible" << endl;
    }









}
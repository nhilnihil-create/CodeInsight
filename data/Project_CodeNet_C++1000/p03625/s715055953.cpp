#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<functional>
#include<set>
#include<map>
#include<utility>
#define ul unsigned long long int
#define ll long long int
#define MAX 1000000+1
using namespace std;
#define F first
#define S second
#define pi 2*acos(0.0)
#define PB push_back
#define LSTAGE 1



int main()
{

    ll n;
    cin >> n;
    map<ll, int> v;
    for(ll i=  0; i < n; i++)
    {
        ll r;
        cin >> r;
        if(v.count(r)==0)
        {
            v[r] = 0;
            v[r]++;
        }
        else v[r]++;

    }
    map<ll, int> :: iterator it;
    ll area = 0;
    ll a= 0, b= 0;
    for(it = v.begin(); it!=v.end(); it++)
    {

//        cout << it->F<<endl;
        if(it->S >= 4)
        {
            area = max(area, it->F*it->F);
        }
        if(it->S>=2)
        {
            b = a;
            a = it->F;
            area = max(area, a*b);
        }
    }
    cout << area ;




    return 0;
}

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
#define Pp push
#define LSTAGE 1
int arr[200010];
ll bfs(vector<int> a[])
{
    queue<int>v;
    v.push(1);
    int t;
    arr[1] = 0;
    int x;
    while(v.size())
    {
        t = v.front();
        v.pop();
        if(arr[t]==2)
            return 1;
        for(int i= 0; i < a[t].size(); i++)
        {
            x = a[t][i];
            if(arr[x]==-1)
            {
                v.push(x);
                arr[x] = arr[t]+1;

            }
        }

    }
    return 0;

}


int main()
{
    ll n, r, t, f, s;
    t = f = s = 0;
    cin >> n;
    for(ll i =0; i< n; i++)
    {
        cin >> r;
        if(r%4==0)
            f++;
        else if(r%2==0)
            t++;
        else
            s++;
    }
    if(t)
        s++;
    if((f+s)/2 <= f)
        cout <<"Yes";
    else
        cout << "No";


    return 0;
}

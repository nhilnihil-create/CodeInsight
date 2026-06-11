#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#define ll long long int

using namespace std;

int n,l;
vector <string> v;

int main()
{
    ///freopen("INA.txt","r",stdin);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>> n >> l;
    for(int i=1;i<=n;i++){
        string s;
        cin>> s;
        v.push_back(s);
    }

    sort(v.begin(),v.end());

    for(int i=0;i<v.size();i++){ cout<< v[i]; }
    cout<< endl;

    return 0;
}


#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define Pause system("pause")
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int main()
{
	IOS;
    ll x,y,cnt0=0,cnt1=0;
    cin>>x>>y;
    if(abs(x-y)>1)
        cout<<"Alice";
    else
        cout<<"Brown";
    return 0;
}
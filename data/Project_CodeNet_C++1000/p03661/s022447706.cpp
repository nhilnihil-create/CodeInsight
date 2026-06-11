#include<iostream>
#include<map>
#include<set>
#include<list>
#include<stack>
#include<queue>
#include<cmath>
#include<string>
#include<time.h>
#include<string.h>
#include<iomanip>
#include<stdlib.h>
#include<algorithm>
typedef long long ll;
const int N = 1e7;
using namespace std;

int main()
{
 	ll a[200005];
	ll num[200005]; //记录每次的abs(差) 
    int n;
    cin >> n;
    ll sum = 0;//记录sum 
    
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
        sum += a[i];
    }
     
    ll s = sum - a[0];//表示Snuke开始 
    ll r = a[0];//表示Raccoon开始 
    num[0] = abs(s-r);//记录第一次 
    
    for (int i = 1;i < n-1;i++)
    {
        r += a[i];//每次多拿一张 
        s -= a[i];//每次少拿一张 
        num[i] = abs(s-r);//记录每次 
    }
    sort(num,num+n-1);//找到最小 
    cout<< num[0] << endl;
    return 0;
}

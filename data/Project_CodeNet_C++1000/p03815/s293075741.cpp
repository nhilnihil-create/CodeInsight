#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{


ll n;
cin >> n;

ll cnt = 0;
ll sum = 0;
if(n>=11)
{
    sum += (n/11)*11 ;
    cnt += (n/11)*2;

}


for(int i=0 ; sum<n    ;i++)
{
    if(i%2==0)
    {
        sum += 6 ;
    }

     else    sum += 5 ;
        cnt++;
}
cout << cnt << endl;

}

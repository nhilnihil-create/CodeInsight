#include<bits/stdc++.h>
#define speed_up ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define ara(A,N) sort(A,A+N)
#define rev(A,N) sort(A,A+N,greater<long long>())
using namespace std;
int main()
{
speed_up;
string s;
cin>>s;
int a[200] = {};
int i, n;
n = s.length();
for(i = 0; i<n; i++)
{
    a[s[i]]++;
}
sort(a, a + 200);
for(i = 0; i<200; i++)
{
    if(a[i]%2 != 0)
    {
        cout<<"No"<<endl;
        return 0;
    }
}
cout<<"Yes"<<endl;

return 0;
}

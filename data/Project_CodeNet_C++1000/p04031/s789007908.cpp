#include<bits/stdc++.h>
#define speed_up ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define ara(A,N) sort(A,A+N)
#define rev(A,N) sort(A,A+N,greater<long long>())
using namespace std;
int main()
{
speed_up;
int n;
vector<int> vec;
cin>>n;
while(n--)
{
    int a;
    cin>>a;
    vec.push_back(a);
}
int mx, mi, i, j, mi_val = INT_MAX;
mx = *max_element(vec.begin(), vec.end());
mi = *min_element(vec.begin(), vec.end());
//cout<<mi<<endl;
for(i = mi ; i<=mx; i++)
{   int sum = 0;
    for(j = 0; j<vec.size(); j++)
    {
         sum += (vec[j]  - i)*(vec[j] - i);
         //cout<<sum<<endl;
    }
    if(sum<mi_val)
    {
        mi_val = sum;
    }

}
cout<<mi_val<<endl;


return 0;
}

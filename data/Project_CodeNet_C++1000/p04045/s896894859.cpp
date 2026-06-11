#include<bits/stdc++.h>
#define speed_up ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define ara(A,N) sort(A,A+N)
#define rev(A,N) sort(A,A+N,greater<long long>())
using namespace std;
int main()
{
speed_up;
int n, k, i, j;
cin>>n>>k;
vector<int> vec;
vector<int>:: iterator it;
i = k;
while(k--)
{
    int a;
    cin>>a;
    vec.push_back(a);
}
while(1)
{
    int num = n, digit, st = 0;
    while(num>0)
    {
        digit = num%10;
        it = find(vec.begin(), vec.end(), digit);
        if(it != vec.end())
        {
            st++;
            break;
        }
        num = num/10;

    }
    if(st == 0)
    {
        cout<<n<<endl;
        return 0;
    }

    n++;

}



return 0;
}

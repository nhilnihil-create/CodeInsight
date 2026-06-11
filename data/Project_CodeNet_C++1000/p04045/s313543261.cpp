#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(inti=a;i<=b;i++)

#define MOD 1000000009
typedef long long int ll;
typedef vector<int>vi;
typedef pair<int,int>pi;



int main()
{
int n,k;
cin>>n>>k;
vector<int> v(10,0);
for(int index = 0 ; index <k;index++)
{
    int c;
    cin>>c;
    v[c]++;
}
vector<int> ans;
int next =1;
while(1)
{
    int a= n;
    next = 1;
    while(a)
    {
        if(v[a%10])
        {
            next = 0;
            break;
        }
        a/=10;
    }
    if(next)
    {
        cout<<n<<endl;
        return 0;
    }
    n++;
}

 return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define repr(i,x,n) for(int i=x; i<(n); i++)
#define ALL(x) (x).begin(),(x).end()
#define INF 1e9
typedef long long ll;
using VI = vector<int>;
using VS = vector<string>;
using graph = vector<vector<int>>;
int main()
{
VI kasi(3);
for (int i = 0; i < 3; i++)
{
    cin>>kasi.at(i);
}

sort(ALL(kasi));
if (kasi.at(0)+kasi.at(1)==kasi.at(2))  
{
    cout<<"Yes"<<endl;
}

else cout<<"No"<<endl;
    return 0;
}
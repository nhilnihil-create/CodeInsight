#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
using namespace std;

typedef long long ll;
typedef short int sh;

const int inf=0x3f3f3f3f;
const int MAX=2e5+10;
const int mod=1e9+7;

int main()
{
    int n;
    while(cin>>n)
        cout<<((n+1)*n>>1)<<endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define REP(i,n) FOR(i,0,n)
#define EACH(itr,v) for(auto itr:v)
#define pb(s) push_back(s)

typedef long long ll;

int main()
{
std:
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;
    if(N==1)
    {
        cout<<0;
        return 0;
    }
    vector<int> vi;
    REP(i,N){
        int x;
        cin>>x;
        vi.pb(x);
    }
    int small=1e9;
    FOR(i,-100,101){
        int sum=0;
        REP(j,N){
            sum+=(vi[j]-i)*(vi[j]-i);
        }
        small=min(small,sum);
    }
    cout<<small;

    return 0;
}

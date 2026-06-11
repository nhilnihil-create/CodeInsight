#include<bits/stdc++.h>
#define int long long
#define vi vector<int>
#define pb push_back
#define log(x,b) (log(b)/log(x))
#define rep(i,x,y) for(int i=(x);i<(y);i++)
using namespace std;
const int mod=1e9+7;

int32_t main()
{
    int w,a,b;
    cin>>w>>a>>b;
    if(b<a)swap(a,b);
    if(a<=b && b<=a+w)cout<<0<<endl;
    else {
        cout<<min(abs(b-(a+w)),abs(b-a))<<endl;
    }

    return 0;
}

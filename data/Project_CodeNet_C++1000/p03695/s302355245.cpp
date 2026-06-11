  
#include <bits/stdc++.h>

using namespace std;

#define fo(i,a,b) for(int i=(a);i<(b);++i)
#define fd(i,b,a) for(int i=(b);i>(a);--i)

typedef long long ll;

int main() {
    int N;cin>>N;
    map<int, int> mp;
    fo(i,0,N) {
        int a;cin>>a;
        mp[min(8, a / 400)]++;
    }
    int min, max;
    min=mp.size()-((mp.count(8))?1:0);
    max=min+mp[8];
    if(min==0)min=1;
    cout<<min<<" "<<max;
    return 0;
}


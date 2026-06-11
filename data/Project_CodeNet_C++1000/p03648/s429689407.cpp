#include <bits/stdc++.h>

using namespace std;

int main()
{
    ///{}
    ios_base::sync_with_stdio(0);
    cin.tie(0);  cout.tie(0);
    long long k;
    cin>>k;
    vector<long long>v(50ll,49ll+k/50ll);
    long long m=k%50ll;
    long long mo=0;
    for(int i=0;i<m;i++){
        v[i]+=50ll-mo-m+1ll;
        mo++;

    }
    for(int i=m;i<50;i++){
        v[i]+=-m;

    }
    cout<<50<<'\n';
    for(int i=0;i<50;i++)
        cout<<v[i]<<' ';
    return 0;
}
/**
10
0 1 1 1 1 1 1 1 1 1
1 0 1 1 1 1 1 1 1 1
1 1 0 1 1 1 1 1 1 1
1 1 1 0 1 1 1 1 1 1
1 1 1 1 0 1 1 1 1 1
1 1 1 1 1 0 1 1 1 1
1 1 1 1 1 1 0 1 1 1
1 1 1 1 1 1 1 0 1 1
1 1 1 1 1 1 1 1 0 1
1 1 1 1 1 1 1 1 1 0
*/

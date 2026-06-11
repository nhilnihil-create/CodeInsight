#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);      cout.tie(0);

    int n,k;
    cin>>n>>k;
    vector<pair<int,long long> >v(n);
    for(int i=0;i<n;i++)
        cin>>v[i].first>>v[i].second;
    int tmk=k;
    int msk=0;
    int imsk=0;
    while(tmk){
        msk|=(1<<imsk);
        imsk++;
        tmk>>=1;
    }
    long long bst=-1ll;
    long long ttl=0ll;
    for(int i=0;i<n;i++){
        if((v[i].first|k)==k)
            ttl+=v[i].second;
    }
    bst=max(bst,ttl);
    for(int i=imsk-1;i>=0;i--){
        ttl=0ll;
        if(k&(1<<i)){
            int nmsk=msk^(1<<i);
            for(int j=0;j<n;j++){
                 if((v[j].first|nmsk)==nmsk)
                    ttl+=v[j].second;
            }
            bst=max(bst,ttl);
        }else{
            msk^=(1<<i);
        }
    }
    cout<<bst<<'\n';
    return 0;
}
/***
3 5
3 3
4 4
2 5
*/

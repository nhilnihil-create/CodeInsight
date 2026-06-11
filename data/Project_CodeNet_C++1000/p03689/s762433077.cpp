#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

#define int int64_t

const int MOD = 1e9+7;
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int H,W,h,w;
    cin>>H>>W>>h>>w;
    if(H%h==0&&W%w==0) {
        cout<<"No";
        return 0;
    }
    cout<<"Yes\n";
    int sum=0;
    if(H%h) {
        int lol = H*W+1;
        int anss[h];
        for(int i=0;i<h;i++) {
            anss[i]=lol;
            if(i==h-1)
                anss[i]=-(h*lol)+lol-1;
        }
        for(int i=0;i<H;i++) {
            for(int j=0;j<W;j++) {
                cout<<anss[i%h]<<" ";
                sum+=anss[i%h];
            }
            
            cout<<"\n";
        }
    }

    else {
        int lol = H*W;
        int anss[w];
        for(int i=0;i<w;i++) {
            anss[i]=lol;
            if(i==w-1)
                anss[i]=-(w*lol)+lol-1;
        }
        for(int i=0;i<H;i++) {
            for(int j=0;j<W;j++) {
                cout<<anss[j%w]<<" ";
                sum+=anss[j%w];
            }
            cout<<"\n";
        }
    }

    //cout<<sum;

    return 0;
}
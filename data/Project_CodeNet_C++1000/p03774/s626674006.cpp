#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int N,M;
    cin>>N>>M;

    int cmax=50;
    vector<int> a(cmax),b(cmax),c(cmax),d(cmax);

    for(int i=0;i<N;i++){
        cin>>a[i]>>b[i];
    }

    for(int i=0;i<M;i++){
        cin>>c[i]>>d[i];
    }

    for(int i=0;i<N;i++){
        int m=abs(a[i]-c[0])+abs(b[i]-d[0]), cp=1;

        for(int j=1;j<M;j++){
            int dist=abs(a[i]-c[j])+abs(b[i]-d[j]);

            if(m>dist){
                m=dist;
                cp=j+1;
            }
        }
        cout<<cp<<endl;
    }
}

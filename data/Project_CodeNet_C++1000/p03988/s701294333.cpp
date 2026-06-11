#include<bits/stdc++.h>
using namespace std;

int main()
{
        int N; cin>>N;
        vector<int> a(N);
        for(int i=0;i<N;i++) cin>>a[i];

        int D=*max_element(a.begin(), a.end());
        vector<int> cnt(N);
        for(int i=0;i<N;i++) cnt[a[i]]++;

        //for(int i=0;i<N;i++) cout<<cnt[i]<<' '; cout<<endl;
        int mn=N;
        for(int i=0;i<=D;i++){
                int d=max(i, D-i);
                mn=min(mn, d);
                if(cnt[d]==0){
                        cout<<"Impossible"<<endl;
                        return 0;
                }
                cnt[d]--;
        }
        //for(int i=0;i<N;i++) cout<<cnt[i]<<' '; cout<<endl;

        for(int i=1;i<=mn;i++) if(cnt[i]>0){
                cout<<"Impossible"<<endl;
                return 0;
        }
        cout<<"Possible"<<endl;
        return 0;
}

    #include <bits/stdc++.h>
    using namespace std;
    #define int long long

    signed main() {
        int n,m,a,b;
        cin>>n>>m;
        bool ans[n]={};
        for(int i=0;i<m;i++){
            cin>>a>>b;
            ans[a-1]=!ans[a-1];
            ans[b-1]= !ans[b-1];
        }
        for(int i=0;i<n;i++){
            if(ans[i]){
                cout<<"NO"<<endl;
                return 0;
            }
        }
        cout<<"YES"<<endl;
    }

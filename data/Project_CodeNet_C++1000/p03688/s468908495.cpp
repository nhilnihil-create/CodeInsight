#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



signed main(){
    ios::sync_with_stdio(false);
	cin.tie(0);


    int n;
    cin>>n;
    int a[n];
    int m = 1e9;
    int M = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        m = min(m,a[i]);
        M = max(M,a[i]);
    }
    int c[n] = {};
    if(M-m>1){
        cout<<"No"<<endl;
        return 0;
    }
    if(m==M){
        if(a[0] == n-1){
            cout<<"Yes"<<endl;
            return 0;
        }
        else{
            n/=2;
            if(n >= a[0]){
                cout<<"Yes"<<endl;
                return 0;
            }
            cout<<"No"<<endl;
            return 0;
        }
    }
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(a[i] == m ) cnt++;
    }

    n -= cnt;
    if(n==1 || M<=cnt || cnt+n/2 < M){
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;

    
    




    
}
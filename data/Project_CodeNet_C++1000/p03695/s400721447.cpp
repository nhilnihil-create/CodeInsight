#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    int n;cin>>n;
    vector<int> a(9);

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x>=3200){
            a[8]++;
        }else{
            a[x/400]++;
        }
        
    }

    int c=0;

    for(int i=0;i<8;i++){
        if(a[i]){
            c++;
        }
    }

    if(c==0){
        cout<<"1 "<<a[8];
    }else{
        cout<<c<<" "<<c+a[8];
    }
    
}

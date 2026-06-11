# include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
int n,x;
int main(){
    cin>>n>>x;
    if(x==1 || x==2*n-1) cout<<"No"<<endl;
    else{
        cout<<"Yes"<<endl;
        for(int i=x-n+1;i<=x+n-1;i++){
           int cnt=i;
           if(cnt>(2*n-1)) cnt-=2*n-1;
           else if(cnt<=0) cnt+=2*n-1;
            cout<<cnt<<endl;
        }
    }
}
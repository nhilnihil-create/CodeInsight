#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
int main(int argc, const char * argv[]) {



    cin.tie(0);
    ios::sync_with_stdio(false);

    int x,y;
    cin>>x>>y;
    if(x==2){
        if(y==2)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    else if(x==4||x==6||x==9||x==11){
        if(y==4||y==6||y==9||y==11){
            cout<<"Yes"<<endl;
        }
        else cout<<"No"<<endl;
    }
    else{
        if(y==1||y==3||y==7||y==8||y==10||y==12){
            cout<<"Yes"<<endl;
        }
        else cout<<"No"<<endl;
    }

    return 0;
}

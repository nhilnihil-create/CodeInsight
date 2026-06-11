#include <bits/stdc++.h>
#define rep(i,s,n) for(int i=s;i<n;i++)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
using P=pair<int,int>;
using G=vector<vector<int>>;
using ll=long long;




int main(){
    int a,b,c; 
    int x[3];
    rep(i,0,3){
        cin>>x[i];
    }

    sort(x,x+3);

    if(x[0]+x[1]==x[2]){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }

    
}

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int gcd(int a,int b){
    if(a%b==0){
        return b;
    }
    else{
        return gcd(b,a%b);
    }
}

int main(){
    int a,b,c,d,ans=0;
    cin>>a>>b>>c>>d;
    vector<int>t(10000);
    t[a]++;
    t[b]--;
    t[c]++;
    t[d]--;
    for(int i=0;i<1000;i++){
        t[i+1]+=t[i];
    }
    for(int i=0;i<1000;i++){
        if(t[i]==2){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
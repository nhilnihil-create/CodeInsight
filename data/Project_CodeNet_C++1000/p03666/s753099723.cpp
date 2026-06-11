#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
int main(){
    ll n,a,b,c,d;
    cin>>n>>a>>b>>c>>d;
    b-=a;
    ll ld=0,lu=0,rd=b+c*(n-1),ru=b+d*(n-1);
    for(int i=0;i<n;i++){
        if(rd<=lu&&ld<=ru){
            cout<<"YES"<<endl;
            return 0;
        }
        ld+=c;
        lu+=d;
        rd-=c;
        ru-=d;
    }
    cout<<"NO"<<endl;
    return 0;
}
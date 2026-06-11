#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define REP(i, n) for(int i = 0; i < n; i++)
using Graph = vector<vector<int>>;

int main(){
    ll ai,ao,at,aj,al,as,az;
    cin>>ai>>ao>>at>>aj>>al>>as>>az;
    
    ll ans1 = ai+aj+al-ai%2-aj%2-al%2;

    ll three = 0;
    ll ans2 = 0;
    if(ai>0&&aj>0&&al>0){
        three = 3;
        ai--;
        aj--;
        al--;
        ans2 = three + ai+aj+al-ai%2-aj%2-al%2; 
    }

    // cout<<ans1+ao<<ans2+ao<<endl;

    cout<< max(ans1,ans2) +ao <<endl;
}
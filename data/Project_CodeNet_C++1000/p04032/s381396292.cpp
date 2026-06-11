#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using Graph = vector<vector<int>>;

int main(){
    string S; cin>>S;
    int N = S.size();
    vector<vector<int>> J(26,vector<int> (N,0));
    rep(i,N){
        int tmp = S.at(i) - 'a';
        J.at(tmp).at(i) = 1;
    }
    rep(i,26){
        rep(j,N-1){
            J.at(i).at(j+1) += J.at(i).at(j);
        }
    }
    int l = -1,r = -1;
    int flag = 0;
    rep(i,26){
        int num = J.at(i).at(N-1);
        // cout<<num<<endl; 
        if(num==0)continue;
        rep1(j,num){
            auto iter1 = lower_bound(J.at(i).begin(),J.at(i).end(),j);
            auto iter2 = lower_bound(J.at(i).begin(),J.at(i).end(),j+1);
            int d1 = distance(J.at(i).begin(),iter1);
            int d2 = distance(J.at(i).begin(),iter2);
            //cout<<(char)('a'+i)<<endl;
            //cout<<d1<<" "<<d2<<endl;
            if(d2-d1+1<=3){
                l = d1+1;
                r = d2+1;
                flag = 1;
                break;
            }
        }
        if(flag)break;
    }
    cout<<l<<" "<<r<<endl;
}

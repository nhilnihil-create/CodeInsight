#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int in() {int x; cin>>x; return x;}
ll lin() {ll x; cin>>x; return x;}
string sin() {string x;cin>>x;return x;}
using graph = vector<vector<int>>;
using graph2 = vector<vector<pair<int, int>>>;

int main() {
    int N, M, K;
    cin>>N>>M>>K;
    int number;
    int check=0;
    rep(i, N+1){
        rep(j, M+1){
            number=M*i+N*j-2*i*j;
            if(number==K){
                check=1;
                goto move;
            }
        }
    }
    move:;
    if (check==1){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}
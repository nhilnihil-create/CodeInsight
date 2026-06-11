#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;

int main(){
    int N, M, A, B, C;
    cin >> N;
    bool reverseFlag = false;
    deque<int> dq;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    rep(i, N){
        if(reverseFlag == false){
            dq.push_back(a[i]);
            reverseFlag = true;
        }else{
            dq.push_front(a[i]);
            reverseFlag = false;
        }
        // cout << reverseFlag << endl;
    }
    if(reverseFlag == false){
        rep(i, N){
        cout << dq.front() << " ";
        dq.pop_front();
        }
    }else{
        rep(i, N){
        cout << dq.back() << " ";
        dq.pop_back();
    }
    }
    
}
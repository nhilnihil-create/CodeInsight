#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

 
int main() {
    int n;
    cin>>n;
    deque<int> q;
    //nが偶数の時
    if(n%2==0){
        rep(i,n/2){
            int a,b;
            cin>>a>>b;
            q.push_back(a);
            q.push_front(b);
        }
        rep(i,n)cout<<q[i]<<" ";
    }else{//nが奇数の時
        int a0;
        cin>>a0;
        q.push_back(a0);
        rep(i,n/2){
            int a,b;
            cin>>a>>b;
            q.push_back(a);
            q.push_front(b);
        }
        rep(i,n)cout<<q[i]<<" ";
    }   
}
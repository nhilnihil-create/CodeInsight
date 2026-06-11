#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    int n;cin>>n;
    deque<int> q;

    for(int i=0;i<n;i++){
        int x;cin>>x;
        if(i&1){
            q.push_front(x);
        }else{
            q.push_back(x);
        }
    }
    if(n&1){
        while(!q.empty()){
            int t=q.back();
            q.pop_back();
            cout<<t<<" ";
        }
    }else{
        while(!q.empty()){
            int t=q.front();
            q.pop_front();
            cout<<t<<" ";
        }
    }
}

#include<iostream>
#include<queue>
using namespace std;
priority_queue <int, vector<int >, greater<int > > q;
int main(){
    int t=3;
    while(t--){
        int i;
        cin>>i;
        q.push(i);
    }
    int ans=0;
    ans+=q.top();
    q.pop();
    ans+=q.top();
    cout<<ans;
    return 0;
}
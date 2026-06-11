#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll mxn= 5e4+5;
// check for forloop
// intialize variable
// overflow
// go for easy solution
#define mod 1000000007
ll INF = 1000000000000000005LL;
//#define endl '\n'
void rishabh(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int main(){
    rishabh();
    int n;
    cin>>n;
    int sum=0;
    priority_queue<int,vector<int>, greater<int>> p;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        sum=sum+x;
        p.push(x);
    }
    while(!p.empty()&&sum%10==0){
        if((sum-p.top())%10!=0){
            sum=sum-p.top();
            break;
        }
        p.pop();
    }
    // cout<<sum<<' ';
    cout<<((sum%10==0)?0:sum);
}
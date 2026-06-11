#include<bits/stdc++.h>
#define N 100005
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define rep(i,s,e) for(int i=s;i<e;i++)
#define drep(i,s,e) for(int i=s;i>e;i--)
#define ll long long
using namespace std;
stack<int> v;
int main(){
    ios_base::sync_with_stdio(0);
    ll n;
    cin>>n;
    n++;
    while(n>1){
        if(n%2){
            v.push(1);
            n--;
        }
        else{
            v.push(2);
            n/=2;
        }
    }
   /*while(!v.empty())
   {
     cout<<v.top();
       v.pop();
   }
    return 0; */ 
   int k=1;
   deque<int> ans;
    while(!v.empty()){
        int u=v.top();
        v.pop();
        if(u==1)
            ans.push_front(k);
        else
            ans.pb(k);
        k++;
    }
    cout<<2*(k-1)<<endl;
    for(int i=1;i<k;i++)
        cout<<i<<' ';
    while(!ans.empty()){
        cout<<ans.front()<<' ';
        ans.pop_front();
    }
    cout<<endl;
    return 0;
}

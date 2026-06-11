#include<bits/stdc++.h>
using namespace std;
#define pb          push_back
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define endl        "\n"
#define fast        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define int         long long int
#define mod         1000000007
#define test        int t;cin>>t;while(t--)
#define REP(i,a,b)  for(int i=a,i<=b;i++)
#define MAXN        200001

void solve(int arr[],int n){

    deque<int>ans;
    for(int i=0;i<n;i++){
        if(i&1)
            ans.push_front(arr[i]);
        else
            ans.push_back(arr[i]);
    }

    if(n&1){
        reverse(all(ans));
        for(auto x:ans){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    else
    {
        for(auto x:ans){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}

int32_t main()
{
    int n;cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    solve(arr,n);
    return 0;
}
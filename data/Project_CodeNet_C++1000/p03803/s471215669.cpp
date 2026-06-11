#include <bits/stdc++.h>
using namespace std;
#define int                  long long int
#define ff                   first
#define ss                   second
#define pb                   push_back
#define mp                   make_pair
#define pii                  pair<int,int>
#define vi                   vector<int>
#define mi                   map<int,int>
#define pqb                  priority_queue<int>
#define pqs                  priority_queue<int,vi,greater<int>>
#define setbits(x)           __builtin_popcountll(x)
#define zrobits(x)           __builtin_ctzll(x)
#define mod                  1000000007
#define inf                  1e18
#define precise(x,y)         fixed<<setprecision(y)<<x
#define w(x)                 int x;cin>>x;while(x--)
#define endl                 "\n"
#define no_of_digit(n)       floor(log10(n))+1
#define copyarr(a,b,n)       copy_n(a,n,b)
mt19937                      rng(chrono::steady_clock::now().time_since_epoch().count());

//*******************to check if all number in array are positive*******************
//all_of(arr,arr+n,[](int x){return x>0;})?cout<<"positive":cout<<"some negative";


//*******************to check if any element in array is negative*******************
//any_of(arr,arr+n,[](int x){return x<0;})?cout<<"Any negative":cout<<"All positive";


int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //*****************Enter the code here*******************//
    int a,b;
    cin>>a>>b;
    if(a==b){
        cout<<"Draw";
    }
    else if(a==1){
        cout<<"Alice";
    }
    else if(b==1)
    {
        cout<<"Bob";
    }
    else if(a<b){
        cout<<"Bob";
    }
    else 
        cout<<"Alice";
    return 0;
}

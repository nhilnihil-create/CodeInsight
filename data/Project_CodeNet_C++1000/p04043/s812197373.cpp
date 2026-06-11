#include <iostream>
#include<cmath>
#include<vector>
#include<tuple>
#include <ctime>
#include<algorithm>
#include <initializer_list>
#include <cstring> 
 
#define tii tuple<int,int>
#define vi vector<int>
#define vii vector<vi>
#define ll long long
#define vl vector<ll>
#define vll vector<vl>
 
#define mymod 1000000007
#define mx 99999999
#define mn -99999999
#define sz 101
 
using namespace std;

int main() {
    clock_t tstart = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // Start
    vi v(3);
    for(auto&x:v) cin>>x;
    sort(v.begin(),v.end());
    if(v[0]==5 && v[1]==5 && v[2]==7){
        cout<<"YES";
    }
    else cout<<"NO";
    // cout<<"\n\nTotal Time Taken : "<<(double)(-tstart + clock())/CLOCKS_PER_SEC<<"sec\n\n";
    return 0;
}
 

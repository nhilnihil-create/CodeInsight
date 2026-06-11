#include <iostream>
#include<iomanip>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#define INF 1e9+7
#define rep(i,n) for(ll i=0;i<n;i++)
#define NO cout<<"NO"<<endl;
#define YES cout<< "YES"<<endl;
#define No cout<< "No"<<endl;
#define Yes cout<< "Yes"<<endl;
#define all(a) a.begin(),a.end()
#define P pair<int,int>
#define space ' '
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

//(int)'a'は97 (int)'A'は65 (int)'1'は49
//おまじない

const int maxn = 100000;
int cnt[maxn+1]={0};

int main(){
    
    int ans = 0;
    int c=0;
    int n;
    cin >> n;
    rep(i,n){
        int t;cin >> t;
        cnt[t]++;
    }
    ans = n;
    rep(i,maxn+1){
        c+=max(0,cnt[i]-1);
    }
    if(c%2==1)c++;
    ans-=c;
    cout <<ans<< endl;
    
    
    
    return 0;
}

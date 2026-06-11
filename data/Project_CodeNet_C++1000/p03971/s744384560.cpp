#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <iomanip> // fixed, setprecision 
#include <math.h> // double sqrt
#define rep(i,n) for(int i=0;i<(n);++i)
#define ll long long
using namespace std;
int main(){
int n,a,b;
cin>>n>>a>>b;
string s;
cin>>s;
int san=0,kaig=0;
rep(i,s.size()){
    if(s[i]=='a'&&san+1<=a+b){cout<<"Yes"<<endl;san++;continue;}
    if(s[i]=='b'&&kaig+1<=b&&san+1<=a+b){cout<<"Yes"<<endl;kaig++;san++;continue;}
     cout<<"No"<<endl;
}
return 0;
}
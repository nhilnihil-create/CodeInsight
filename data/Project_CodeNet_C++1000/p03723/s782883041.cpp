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
    int a,b,c;
    cin>>a>>b>>c;
    if(a==b&&a==c&&a%2==0&&b%2==0&&c%2==0){
        cout<<-1;
        return 0;
    }
int count=0;
while(1){
    ll p=a,q=b,r=c;
    if(a%2==1||b%2==1||c%2==1){cout<<count;return 0;}
    b=p/2+r/2;
    a=q/2+r/2;
    c=p/2+q/2;
    count++;
}
cout<<count;
return 0;
}
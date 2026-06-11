#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include <bitset>
#include <cmath>
#include <limits>
#include <iostream>
#include<set>
#include<tuple>
using namespace std;
#define INF 11000000000
#define MAX 100000
#define MOD 1000000007
typedef long long ll;
typedef pair<int,int> P;
typedef pair<pair<int,int>,int> p;
typedef pair< pair<int,int>, int> p; 
#define bit(n,k) ((n>>k)&1) /*nのk bit目*/
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)

int main(){
    int N;
    cin>>N;
    ll num=0,ten=0;
    for(int i=0;i<N;i++){
        ll a,b;
        cin>>a>>b;
        if(num<a){
            num=a; ten=b;
        }
    }
    cout<<num+ten<<endl;
}


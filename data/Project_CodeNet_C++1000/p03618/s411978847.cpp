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
#define MAX 5100
#define MOD 1000000007
typedef long long ll;
typedef pair<int,int> P;
typedef pair<pair<int,int>,int> p;
typedef pair< pair<int,int>, int> p; 
#define bit(n,k) ((n>>k)&1) /*nのk bit目*/
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)

ll C[26];

int main(){
    string s;
    cin>>s;
    ll n=s.size();
    for(int i=0;i<(int)s.size();i++){
        C[s[i]-'a']++;
    }
    ll ans=1+n*(n-1)/2;
    for(int i=0;i<26;i++){
        ans-=C[i]*(C[i]-1)/2;
    }
    cout<<ans<<endl;
}


#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<P,P> PP;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=9999999999;


int main(){
    int n;
    string s;
    cin>>n>>s;
    int left=0, right=0;
    int l=0, r=0;
    for(int i=0;i<n;i++){
        if(s[i]==')'){
            if(left==0){
                l++;
            }else{
                left--;
            }
        }else{
            left++;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(s[i]=='('){
            if(right==0){
                r++;
            }else{
                right--;
            }
        }else{
            right++;
        }
    }
    reverse(s.begin(),s.end());
    while(l){
        s+='(';
        l--;
    }
    reverse(s.begin(),s.end());
    while(r){
        s+=')';
        r--;
    }
    cout<<s<<endl;


}
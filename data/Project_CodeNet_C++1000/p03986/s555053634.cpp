#include<algorithm>
#include<bitset>
#include<cmath>
#include<cstdlib>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<string>
#include<utility>
#include<vector>

using namespace std;
 
typedef long long ll;
const ll MOD = 1e9+7;
const ll INF = 1e18;


#define PB push_back
#define MP make_pair
#define F first
#define S second

template<typename T,typename U>
bool chmax(T& max, const U& x){
	if(max<x){
		max = x;
		return true;
	}
	return false;
}

template<typename T,typename U>
bool chmin(T& min, const U& x){
	if(min>x){
		min = x;
		return true;
	}
	return false;
}


int main(){
	string s;
    cin >> s;
    vector<ll> ans(2,0); //tの数,sの数
    if(s[0]=='S'){
        ans[1]++;
    }else{
        ans[0]++;
    }
    for(ll i=1;i<s.size();i++){
        if(s[i]=='S'){
            ans[1]++;
        }else{
            if(ans[1]>0){
                ans[1]--;
            }else{
                ans[0]++;
            }
        }
    }

    cout << ans[0]+ans[1]<<endl;
}

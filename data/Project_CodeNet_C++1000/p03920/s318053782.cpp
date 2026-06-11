#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;
    ll i,cnt=0;
    for(i=1;;i++){
        cnt+=i;
        if(cnt>=n)  break;   
    }
    for(ll j=i;n>0;j--){
        if(n>=j){
                n-=j;
                cout << j << endl;
        }
    }
	return 0;
}
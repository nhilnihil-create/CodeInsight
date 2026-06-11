#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <limits.h>

using namespace std;

#define rip(i, n, s) for (int i = (s);i < (int)( n ); i++)
#define all(a) (a).begin(), (a).end()
typedef long long ll;

template<typename T>
void vdeb(vector<T> &da){
    int size=da.size();
    for(int i=0;i<size;i++){
        if(i==size-1){
            cout << da[i] << endl;
        }
        else{
            cout << da[i] << ' ';
        }
    }
}

ll comb(int a, int b){
	ll ret = 1;
	rip(i,b,0){
		ret*=a-i;
		ret/=i+1;
	}
	return ret;
}

int main(){
	int n,a,b;
	cin >> n >> a >> b;
	vector<ll> da(n);
	rip(i,n,0){
		cin >> da[i];
	}
	map<ll,int> mp;
	rip(i,n,0){
		if(mp.count(da[i])){
			mp[da[i]]++;
		}
		else{
			mp[da[i]]=1;
		}
	}
	auto itr = mp.end();
	--itr;
	if((*itr).second > a){
		ll ans = 0;
		cout << (*itr).first << endl;
		rip(i,min(b,(*itr).second)+1,a){
			ans += comb((*itr).second,i);
		}
		cout << ans << endl;
	}
	else{
		int co = a;
		ll ret = 0;
		while((*itr).second < a){
			ret += (ll)(*itr).first * (*itr).second;
			a-=(*itr).second;
			--itr;
		}
		ret += (ll)(*itr).first * a;
		printf("%.07f\n",(double)ret/co);
		cout << comb((*itr).second,a) << endl;
	}
}
//#include "pch.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <limits.h>
#include <string>
#include <deque>
#include <cmath>
#include <bitset>
#include <complex>
#include <time.h>
#include <stdio.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

#define rip(i, n, s) for (int i = (s);i < (int)( n ); i++)
#define mpa make_pair
#define all(a) a.begin(), a.end()

template<typename T>
void vdeb(vector<T> &da) {
	int size = da.size();
	for (int i = 0;i < size;i++) {
		if (i == size - 1) {
			cout << da[i] << endl;
		}
		else {
			cout << da[i] << ' ';
		}
	}
}
template<typename T>
void vvdeb(vector<T> &da) {
	int size = da.size();
	for (int i = 0;i < size;i++) {
		vdeb(da[i]);
	}
}

template<typename T>
struct BIT{
    vector<T> li;
    int size;
    BIT (int n){
        li=vector<T>(n+1,0);
        size=n;
    }
    T sum (int i){
        int s=0;
        while(i>0){
            s+=li[i];
            i-=i & -i;
        }
        return s;
    }
    void add(int i,T x){
        while(i<=size){
            li[i]+=x;
            i+=i & -i;
        }
    }
};

int main(){
	int n,k;cin >> n >> k;
	vector<ll> da(n);
	vector<P> li(n+1);
	li[0]= mpa(0,0);
	ll now = 0;
	rip(i,n,0){
		cin >> da[i];
		da[i]-=k;
		now += da[i];
		li[i+1] = mpa(now, i+1);
	}
	sort(all(li));
	rip(i,n+1,0){
		li[i].first = i;
		swap(li[i].first, li[i].second);
	}
	//rip(i,n+1,0) cout << li[i].first << endl;
	sort(all(li));
	BIT<int> bt(n+1);
	ll ans = 0;
	bt.add(li[0].second+1,1);
	rip(i,n+1,1){
		//vdeb(bt.li);
		ans += bt.sum(li[i].second+1);
		bt.add(li[i].second+1,1);
	}
	cout << ans << endl;
}
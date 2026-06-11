#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <string>
 
using namespace std;
 
#define rip(i, n, s) for (int i = (s);i < ( int )( n ); i++)
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
template<typename T>
void vvdeb(vector<T> &da){
    int size=da.size();
    for(int i=0;i<size;i++){
        vdeb(da[i]);
    }
}

int main(){
	int n;
	ll a,b,c,d;
	cin >> n >> a >> b >> c >> d;
	if(a-(n-1)*d > b){
		cout << "NO" << endl;
		return 0;
	}
	if(a+(n-1)*d < b){
		cout << "NO" << endl;
		return 0;
	}
	int ok=0,ng=n;
	while(ng-ok!=1){
		int now=(ok+ng)/2;
		if(a+now*c-(n-now-1)*d > b){
			ng=now;
		}
		else{
			ok=now;
		}
	}
	a+=ok*c-(n-ok-1)*d;
	b-=a;
	if(b <= (n-1)*(d-c)){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}
}

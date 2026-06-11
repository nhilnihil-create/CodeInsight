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
	ll now=a+(ll)(n-1)*d;
	if(b>now || b<a-(ll)(n-1)*d){
		cout << "NO" << endl;
		return 0;
	}
	rip(i,n-1,0){
		now-=c+d;
		if(now < b){
			now+=c+d;
			break;
		}
	}
	now-=(ll)(n-1)*(d-c);
	if(now>b){
		cout << "NO" << endl;
	}
	else{
		cout << "YES" << endl;
	}
}
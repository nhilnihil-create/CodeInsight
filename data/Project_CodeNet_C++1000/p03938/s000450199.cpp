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
	cin >> n;
	vector<int> da(n);
	rip(i,n,0){
		cin >> da[i];
	}
	vector<int> a(n),b(n);
	rip(i,n,0){
		a[i]=i*n+1;
		b[n-i-1]=i*n+1;
	}
	rip(i,n,0){
		a[da[i]-1]+=i;
		b[da[i]-1]+=i;
	}
	vdeb(a);
	vdeb(b);
}
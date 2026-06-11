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
template<typename T>
void vvdeb(vector<T> &da){
    int size=da.size();
    for(int i=0;i<size;i++){
        vdeb(da[i]);
    }
}

int main(){
	int h,w;
	int n;
	cin >> h >> w >> n;
	vector<int> da(n);
	rip(i,n,0){
		cin >> da[i];
	}
	vector<vector<int>> ans(h,vector<int>(w));
	int now=0;
	rip(i,h,0){
		rip(j,w,0){
			if(i%2){
				ans[i][j]=now+1;
			}
			else{
				ans[i][w-j-1]=now+1;
			}
			da[now]--;
			if(da[now]==0){
				now++;
			}
		}
	}
	vvdeb(ans);
}
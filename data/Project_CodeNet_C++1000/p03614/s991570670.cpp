#include <bits/stdc++.h>
#define MAXN 100100
#define pii pair<int, int>
#define pb push_back
typedef long long ll;

using namespace std;

int n, a[MAXN], ans = 0;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    for(int i = 0; i < n; i++){
    	if(a[i] == i + 1){
    		if(a[i + 1] == i + 2){
    			i++;
    			ans++;
    		} else{
    			ans++;
    		}
    	}
    }
    cout << ans;
}
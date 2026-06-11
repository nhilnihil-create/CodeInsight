#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vt vector
#define pb push_back
#define pob pop_back
#define ii pair<int,int>
#define vi vt<int>
#define vvi vt<vi>
#define vii vt<ii>
#define vvii vt<vii>
typedef long long ll;
#define For(i,a,b) for(int i = a; i < b; i++)
#define foR(i,a,b) for(int i = a; i <= b; i++)
#define roF(i,a,b) for(int i = a - 1; i >= b; i--)
#define Rof(i,a,b) for(int i = a; i >= b; i--)
#define N 100000
#define lg 20
int hotel[N];
int last[N][lg];
queue<ii> q;
signed main (){
	/*
	freopen(".inp","r",stdin);
	freopen(".out","w",stdout);
	*/
	int n, l;
	cin >> n;
	For(i,0,n){
		cin >> hotel[i];
	}
	cin >> l;
	For(i,0,n){
		q.push(ii(hotel[i], i));
		while(q.back().first > q.front().first+l){
			last[q.front().second][0] = q.back().second-1;
			q.pop();
		}
	}
	while(!q.empty()){
		last[q.front().second][0] = q.back().second;
		q.pop();
	}
//	For(i,0,n){
//		cout << last[i] << " ";
//	}
	For(j,1,20){
		For(i,0,n){
			last[i][j] = last[last[i][j-1]][j-1];
		}
	}
	int q, a, b;
	cin >> q;
	while(q--){
		cin >> a >> b;
		if(a > b){
			swap(a,b);
		}
		a--;b--;
		int coun = 1;
		roF(i,20,0){
			if(last[a][i] < b){
				a = last[a][i];
				coun += 1<<i;
			}
		}
		cout << coun << "\n";
	}
}


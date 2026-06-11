#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define sz(x) (int)(x.size())
#define fr(i,a,b) for(int i=a;i<b;++i)
/////////////////////

vector<int> a, b;
int n, m;

void bad(){
	cout << "Impossible" << endl;
	exit(0);
}

void solve(){
	cin >> n >> m;
	a.resize(m);
	int cnt = 0;
	fr(i, 0, m){
		cin >> a[i];
		cnt += (a[i] % 2);
	}
	if(m == 1){
		cout << a[0] << endl;
		if(n > 1){
			cout << 2 << endl;
			cout << a[0] - 1 << " " << 1 << endl;
		}else{
			cout << 1 << endl;
			cout << a[0] << endl;
		}
		return;
	}
	if(cnt > 2) bad();
	fr(i, 0, m) if(a[i] % 2 == 1){
		swap(a[i], a[0]);
		break;
	}
	fr(i, 1, m) if(a[i] % 2 == 1){
		swap(a[i], a[m-1]);
		break;
	}
	b = a;

	b[0] += 1;
	b.back() -= 1;
	if(b.back() == 0) b.pop_back();
	fr(i, 0, m) cout << a[i] << " ";
	cout << endl;
	cout << sz(b) << endl;
	fr(i, 0, sz(b)) cout << b[i] << " ";
	cout << endl;

}

int main(){
#ifdef _DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	solve();


	return 0;
}
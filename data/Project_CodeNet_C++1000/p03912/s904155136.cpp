#include<bits/stdc++.h>

#define reps(i,j,k) for(int i=(j);i<(k);i++)
#define rep(i,j) reps(i,0,j)
#define fs first
#define sc second
#define pb push_back
#define mk make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

template<class S,class T>
ostream &operator<<(ostream &out, const pair<S,T> p){
	return out << "(" << p.fs << ", " << p.sc << ")";
}

template<class T>
ostream &operator<<(ostream &out, const vector<T> &v){
	out << "{";
	rep(i,v.size()) out << v[i] << ", ";
	return out << "}" << endl;
}

int main(){
	int m,n;
	cin >> n >> m;
	vi c(n);
	vi q(m+1,0);
	vi eqs(m,0);
	rep(i,n){
		cin >> c[i];
		q[c[i] % m]++;
	}

	int cnt = 0;
	sort(c.begin(),c.end());
	rep(i,n-1){
		if(c[i]==c[i+1])
			eqs[c[i++]%m]+=2;;
	}
	cnt = q[0] / 2;
	reps(i, 1, (m+1)/2){
		int t = min(q[i], q[m-i]);
		cnt += t;
		cnt += min(q[i] - t, eqs[i]) / 2;
		cnt += min(q[m-i] - t, eqs[m-i]) / 2;
	}
	if(m%2==0) cnt += q[m/2] / 2;

	cout << cnt << endl;
	return 0;
}


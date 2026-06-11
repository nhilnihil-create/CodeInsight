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
	string s,t;
	cin >> s;
	t = s;
	reverse(t.begin(), t.end());
	rep(i,t.length()){
		char c = '_';
		switch(t[i]){
			case 'b':
				c = 'd';
				break;
			case 'd':
				c = 'b';
				break;
			case 'p':
				c = 'q';
				break;
			case 'q':
				c = 'p';
				break;
			default: break;
		}
		t[i] = c;
	}
	cout << (t == s ? "Yes": "No") << endl;

	return 0;
}

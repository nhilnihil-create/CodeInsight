
// Problem : C - Sequence
// Contest : AtCoder - AtCoder Beginner Contest 059
// URL : https://atcoder.jp/contests/abc059/tasks/arc072_a
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

#define spc ' '
#define endl '\n'

using namespace std;


int main(){
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, curr1 = 0, curr2 = 0;
	long long t1 = 0ll, t2 = 0ll;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i <n ; ++i){
	    cin >> a[i];
	    curr1 += a[i];
	    if(i%2==0 && curr1>=0){
	        t1+=curr1+1;
	        curr1=-1;
	    }
	    else if(i%2==1 && curr1<=0){
	        t1+=-curr1+1;
	        curr1 = 1;
	    }
	    curr2+=a[i];
	    if(i%2==0 && curr2<=0){
	        t2+=-curr2+1;
	        curr2=1;
	    }
	    else if(i%2==1 && curr2>=0){
	        t2+=curr2+1;
	        curr2 = -1;
	    }
	}
	cout << min(t1,t2);
	return 0;
}
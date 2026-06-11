#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int h,w;
    cin>>h>>w;
    string s;
    int a[26]={0};
    for(int i=0;i<h;i++){
    	cin>>s;
    	for(int j=0;j<w;j++){
    		a[s[j]-'a']++;
    	}
    }
    int c1=0,c2=0;
    for(int i=0;i<26;i++){
    	a[i]%=4;
    	if(a[i]>1)c2++;
    	if(a[i]&1)c1++;
    }
    if(h&1){
    	if(w&1)cout << ((c1>1||c2>(w/2+h/2))?"No":"Yes") <<endl;
    	else cout << ((c1||2*c2>w)?"No":"Yes") <<endl;
    }else{
    	if(w&1) cout << ((c1||2*c2>h)?"No":"Yes") <<endl;
    	else cout << ((c1||c2)?"No":"Yes")<<endl;
    }
    return 0;
}

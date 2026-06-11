#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
const ll inf=1e18;
const int N=3e5+3;
multiset<int> s;
multiset<int,greater<int> > t;
ll a[N],b[N],c[N];
int n;
int main(){
    cin>>n;
    ll tmp=0,ans=-inf;
    for(int i=1;i<=n*3;i++){
    	cin>>a[i];
    	s.insert(a[i]);
    	tmp+=a[i];
    	if(s.size()>n){
    		tmp-=(*s.begin());
    		s.erase(s.begin());
    	}
    	b[i]=tmp;
    }
    tmp=0;
    for(int i=n*3;i>=1;i--){
    	t.insert(a[i]);
    	tmp+=a[i];
    	if(t.size()>n){
    		tmp-=(*t.begin());
    		t.erase(t.begin());
    	}
    	c[i]=tmp;
    }
    for(int i=n;i<=(n<<1);i++) ans=max(ans,b[i]-c[i+1]);
    cout<<ans<<endl;
    return 0;
}
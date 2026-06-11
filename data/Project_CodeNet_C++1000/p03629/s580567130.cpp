#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define lol(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
typedef long long ll;
using namespace std;
#define N 200010
int main(){
    string s;
    vector<int> v[26];
    cin>>s;
    lol(i,s.size()){
	v[s[i]-'a'].push_back(i);
    }
    lol(i,26){
	v[i].push_back(-1);
	sort(v[i].begin(),v[i].end());
    }
    
    int surf[N];
    int p=s.size(),len=0;
    while(true){
	int mini=mod;
	lol(i,26){
	    int t=*(lower_bound(v[i].begin(),v[i].end(),p)-1);
	    mini=min(mini,t);
	}
	if(mini==-1)break;
	surf[len]=p=mini;
	len++;
    }
    
    len--;
    p=-1;
    for(;len>=0;len--){
	lol(i,26){
	    int t=*upper_bound(v[i].begin(),v[i].end(),p);
	    if(surf[len]<=t){
		char z=i+'a';
		cout<<z;
		p=t;
		break;
	    }
	}
    }
    lol(i,26){
	if(upper_bound(v[i].begin(),v[i].end(),p)==v[i].end()){
	    char z=i+'a';
	    cout<<z<<endl;
	    break;
	}
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    // string s;
    // cin>>s;
   	// int flag=1;
    // for(int i=0;i<s.size();++i){
    // 	for(int j=i+1;j<s.size();++j){
    // 		if(s[i]==s[j]){
    // 			flag=0;
    // 			break;
    // 		}
    // 	}
    // }
    // cout<<((flag)?"yes":"no");



    // string s;
    // cin>>s;
    // set<char>c;
    // for(char k:s) c.insert(k);
    // cout<<((s.size()==c.size())?"yes":"no");
    


    // string s;
    // cin>>s;
    // map<char,int>m;
    // for(int i=0;i<s.size();++i){
    // 	if(m[s[i]]>0){
    // 		cout<<"no";
    // 		return 0;
    // 	}
    // 	++m[s[i]];
    // }
    // cout<<"yes";

    // int a,b;
    // cin>>a>>b;
    // int ans=a+b;
    // (ans>=10)?cout<<"error":cout<<ans;
    

    // int n;
    // cin>>n;
    // int a,mx=0,mi=1000;
    // for(int i=0;i<n;++i){
    // 	cin>>a;
    // 	if(mx<a) mx=a;
    // 	if(mi>a) mi=a;
    // }


    // int n;
    // cin>>n;
    // int ar[n];
    // for(int i=0;i<n;++i) cin>>ar[i];
   	// cout<<*max_element(ar,ar+n)-*min_element(ar,ar+n);
    

    // int n,m;
    // cin>>n>>m;
    // n+=2;
    // m+=2;
    // for(int i=0;i<n;++i){
    // 	for(int j=0;j<m;++j){
    // 		if(i==0 || i==n-1 || j==0 || j==m-1) cout<<"#";
    // 		else{
    // 			char c;
    // 			cin>>c;
    // 			cout<<c;
    // 		}
    // 	}
    // 	cout<<'\n';
    // }

    // int x,y;
    // cin>>x>>y;
    // int ar[13]={0,1,3,1,2,1,2,1,1,2,1,2,1};
    // cout<<((ar[x]==ar[y])?"Yes":"No");
    

    // string a,b,c;
    // cin>>a>>b>>c;
    // cout<<(((a.back()==b.front()) && (b.back()==c.front()))?"YES":"NO");
    
    // int a,b,c;
    // cin>>a>>b>>c;
    // cout<<((a<=c && c<=b)?"Yes":"No");
   
	// string s(3,'0');
	// for(int i=0;i<3;++i) cin>>s.at(i);
	// int x=stoi(s);
	// cout<<((x%4==0)?"YES":"NO");       

    // int a,b,c;
    // cin>>a>>b>>c;
    // cout<<(((b*10+c)%4==0)?"YES":"NO");

    // int n,m;
    // cin>>n>>m;
    // m*=2;
    // int ar[m];
    // for(int i=0;i<m;++i) cin>>ar[i];
    // for(int i=1;i<=n;++i) cout<<count(ar,ar+m,i)<<'\n'; 
   
    // int n,m;
    // cin>>n>>m;
    // vector<int>num(n,0);
    // for(int i=0;i<m;++i){
    // 	int a,b;
    // 	cin>>a>>b;
    // 	++num.at(a-1);
    // 	++num.at(b-1);
    // }
    // for(int i=0;i<n;++i) cout<<num[i]<<'\n';
   
    int a,b,c;
    cin>>a>>b>>c;
    int flag=0;
    for(int i=1;i<=b;++i){
    	if(a*i%b==c){
    		flag=1;
    		break;    
    	}
    }
    cout<<((flag)?"YES":"NO");
   return 0;
}
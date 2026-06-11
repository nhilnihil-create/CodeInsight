#include<bits/stdc++.h>
using namespace std;
template<typename T>vector<T>&operator<<(vector<T>&v,const T t){v.push_back(t);return v;}
template<typename T>multiset<T>&operator<<(multiset<T>&m,const T t){m.insert(t);return m;}
template<typename T,typename U>istream&operator>>(istream&s,pair<T,U>&p){return s>>p.first>>p.second;}
template<typename T,typename U>ostream&operator<<(ostream&s,const pair<T,U>p){return s<<p.first<<" "<<p.second;}
template<typename T>ostream&operator<<(ostream&s,const vector<T>v){for(auto a:v){s<<a<<endl;}return s;}
#define all(x) x.begin(),x.end()
typedef pair<int,int>pii;

int p[2][200001];
int r[2][200001];
int uni(int j,int i){
	return p[j][i]=p[j][i]&&p[j][i]!=i?uni(j,p[j][i]):i;
}

int N,KL[2];
pair<pii,int>s[200001];
int ans[2000001];

main(){
	cin>>N>>KL[0]>>KL[1];
	for(int j=0;j<2;++j){
		for(int i=0;i<KL[j];++i){
			int a,b;
			cin>>a>>b;
			a=uni(j,a);
			b=uni(j,b);
			if(a!=b){
				if(r[j][a]<r[j][b]){
					p[j][a]=b;
				}else{
					p[j][b]=a;
					if(r[j][a]==r[j][b]){
						++r[j][a];
					}
				}
			}
		}
	}
	for(int i=1;i<=N;++i){
		s[i]={{uni(0,i),uni(1,i)},i};
	}
	sort(s+1,s+1+N);
	for(int i=1;i<=N;){
		int j=i+1,c=1;
		for(;j<=N&&s[i].first==s[j].first;++j){
			++c;
		}
		for(;i<j;++i){
			ans[s[i].second]=c;
		}
	}
	for(int i=1;i<=N;++i){
		cout<<ans[i]<<(i==N?"\n":" ");
	}
}

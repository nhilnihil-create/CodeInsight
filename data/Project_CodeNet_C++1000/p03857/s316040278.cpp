#include <iostream>
#include <bits/stdc++.h>
#include <time.h>
#include <sys/timeb.h>
#include <cstdio>
#include <sys/time.h>

using namespace std;
#define ll long long
#define uint unsigned int
#define ulong unsigned long long int

template<typename T> bool InRange(T t, T l, T r){ return l <= t && t < r; }

class UnionFind{
private:
	vector<int> parent;
	vector<int> mem;
	int compo;
	int N;
public:
	UnionFind(int n_){
		Initialize(n_);
	}
	
	void Initialize(int n_){
		N=n_;
		parent.resize(N);
		mem.resize(N);
		for(int i=0;i<N;i++){
			parent[i]=i;
			mem[i]=1;
		}
		compo = N;
	}
	
	int Parent(int a){
		if(parent[a] == a)return a;
		return parent[a] = Parent(parent[a]);
	}
	
	bool IsUnited(int a, int b){
		return Parent(a) == Parent(b);
	}
	
	void Unite(int a, int b){
		a = Parent(a); b = Parent(b);
		if(a == b) return;
		parent[a] = b;
		mem[b] += mem[a];
		compo -= 1;
	}
	
	bool IsRoot(int x){
		return x == parent[x];
	}
	int MemCnt(int x){
		return mem[Parent(x)];
	}
	
	int Compo(){
		return compo;
	}
	
};

int main(){
	
	int N, K, L;
	cin >> N >> K >> L;
	vector<int> P(K), Q(K);
	for(int i=0;i<K;i++) cin >> P[i] >> Q[i];
	for(int i=0;i<K;i++) P[i]--, Q[i]--;
	vector<int> R(L), S(L);
	for(int i=0;i<L;i++) cin >> R[i] >> S[i];
	for(int i=0;i<L;i++) R[i]--, S[i]--;
	
	
	UnionFind UF1(N);
	for(int i=0;i<K;i++) UF1.Unite(P[i], Q[i]);
	
	UnionFind UF2(N);
	for(int i=0;i<L;i++) UF2.Unite(R[i], S[i]);
	
	vector<ll> compoHash(N);
	ll mod = N;
	for(int i=0;i<N;i++){
		compoHash[i] = UF1.Parent(i) * mod + UF2.Parent(i);
	}
	
	map<ll,ll> mp;
	for(int i=0;i<N;i++) mp[compoHash[i]]++;
	
	for(int i=0;i<N;i++){
		printf((i == 0 ? "%d" : " %d"), mp[compoHash[i]]);
	}
	printf("\n");
	
    return 0;
}
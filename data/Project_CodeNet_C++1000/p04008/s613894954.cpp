#include <bits/stdc++.h>
using namespace std;

#define dforsn(i,s,n) for(int i=int(n-1);i>=int(s);i--)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) for(int i=int(n-1);i>=0;i--)
#define forn(i,n) for(int i=0;i<int(n);i++)
#define D(a) cerr << #a << " = " << a << endl
#define all(a) a.begin(),a.end()
#define si(a) int((a).size())
typedef pair<int,int> pii;
typedef long long int ll;
typedef vector<int> vi;
#define pb emplace_back
#define mp make_pair
#define snd second
#define fst first

int incidencia[100001];
int tps[100001];
int altura[100001];
bool tocados[100001];

priority_queue<pii> explorar;

vi hojas;
int r = 0, n,k;

void calcularAltura(int nodo){
	if(tps[nodo] == 1)
		altura[nodo] = 1;
	else {
		if(altura[tps[nodo]] == 0)
			calcularAltura(tps[nodo]);
		
		altura[nodo] = 1 + altura[tps[nodo]];
	}
}

void reenchufar(){
	int actual = explorar.top().snd;
	int siguiente = tps[actual];

	explorar.pop();
	
	forn(i,k-1){
		if(tocados[actual])
			return;
		
		tocados[actual] = true;
		
		if(siguiente == 1)
			break;
		
		actual = siguiente;
		siguiente = tps[actual];
		
	}
	
	if(siguiente != 1){
		incidencia[siguiente]--;
		r++;
		tps[actual] = 1;
	}
	
	if(incidencia[siguiente] == 0)
		explorar.push(mp(altura[siguiente],siguiente));
	
	return;

}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
		
	// setear altura como -1 o con 0 anda;
		
	cin >> n >> k;
	forsn(i,1,n+1){
		cin >> tps[i];
		incidencia[tps[i]]++;
	}
	
	// Se enchufa la capital a si misma
	if(tps[1] != 1){
		incidencia[tps[1]]--;
		incidencia[1]++;
		tps[1] = 1;
		r++;
	}
	
	// Se meten las hojas en hojas y se calcula la altura de cada nodo, la capital nunca va a ser una hoja
	// Ahora se meten en la priqueue por orden de pistruli

	
	forsn(i,1,n+1){
		if(incidencia[i] == 0){
			hojas.pb(i);
			calcularAltura(i);
			explorar.push(mp(altura[i],i));
		}
	}
	
	// Con la pq se hace el reenchufe de antes
	while(si(explorar)){
		reenchufar();
	}
	
	cout << r << endl;
	
    return 0;
}
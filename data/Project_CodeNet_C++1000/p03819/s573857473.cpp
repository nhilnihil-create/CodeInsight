// Aimi >> Konomi Suzuki >> Yui >>  Ikimono Gakari >> Garninelia >> Kalafina... dude?
 
// .... Sempre Amei Você ...
 
// Sempre amei você
// Mesmo de longe sem te ter
// Você me deu forças para viver
// E ser quem eu queria ser
// 
// 
// Você nunca verá uma menina como ela
// Mais linda em sentimentos que romance de novela
// Bela, ingênua, tipo como cinderela
// Sorte é do homem que estiver ao lado dela
// Guerreira, não compare com as demais
// Lutou muito para cumprir a exigência de seus pais
// Sua força vai além do que cê pensa ser capaz
// Essa menina não desiste daquilo que vai atrás, mas
// Eu fui tão cego pra não ver
// Que apenas ao meu lado ela queria viver
// Enquanto que por outra pessoa eu quis correr
// Ela não desistiu de mim mesmo eu a fazendo sofrer
// Que idiota, como eu não pude perceber?
// Que a menina que me amava estava sempre ali pra ver
// Eu sei que esse sentimento eu não mereço ter
// Mas desta vez eu vou tentar com meus erros aprender
//
// 
// Sempre amei você
// Mesmo de longe sem te ter
// Você me deu forças para viver
// E ser quem eu queria ser
// 
// 
// Ela sempre esteve lá, pra me ajudar
// Quando eu caí, me fez levantar
// Lutei tanto por meu sonho que sempre quis alcançar
// Que acabei ficando cego sem poder enxergar
// Eu nem consegui notar
// Que bem na minha frente era quem deveria amar
// Sempre achei que estava certo e que não podia errar
// Mas só mesmo quando perde pra então valorizar
// E eu perdi, e finalmente entendi
// Que quem eu procurava estava sempre ali
// Levou muito tempo pra ficha cair
// Como eu fui tapado, eu tenho que admitir
// Essa menina conseguiu me surpreender
// Seu olhar estava sempre além do que eu podia ver
// Eu tive que a perder, só pra perceber
// Que ao lado dela é onde eu quero viver
// 
// 
// Sempre amei você
// Mesmo de longe sem te ter
// Você me deu forças para viver
// E ser quem eu queria ser
// 
// 
// Eu tive que a perder
// Pra que pudesse perceber
// Que ao lado dela
// É onde eu quero viver
// Sim, um dia pode ser o fim
// Pode ser tarde demais e tudo acabar assim
// Mas pra ela eu vou dizer
// Não volto com minha palavra
// Com você quero viver
// 
// 
// Sempre amei você
// Mesmo de longe sem te ter
// Você me deu forças para viver
// E ser quem eu queria ser 
 
#pragma GCC optimize ("Ofast,unroll-loops")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
 
#define pb push_back
#define ff  first
#define ss second
#define tm1 first
#define tm2 second.first
#define tm3 second.second
#define sz(x) ll(x.size())
#define fill(x, v) memset(x, v, sizeof(x))
#define all(v) (v).begin(), (v).end()
#define FER(i,a,b) for(ll i=ll(a); i< ll(b); ++i)
#define IFR(i,a,b) for(ll i=ll(a); i>=ll(b); --i )
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
 
#define N 6800015
#define M 21
#define sqr(x) (x)*(x)
#define INF 20000000000000000
#define mod 1000000007
#define bas 31
#define pi acos(-1) 
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ii > tri;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> set_t;
 
#define trace(...) f(#__VA_ARGS__, __VA_ARGS__)
 
template<typename t> void f(const char* x, t&& val1){
    cout<<x<< " : "<<val1<<endl;
}
template<typename t1, typename... t2> void f(const char* x, t1&& val1, t2&&... val2){
    const char* xd=strchr(x+1, ',');
    cout.write(x, xd-x)<<" : "<<val1<<" | ";
    f(xd+1, val2...);
}

struct ST{
	ll n, t[1<<21];
	inline ll Op(ll &val1, ll &val2){
		return val1+val2;
	}
	inline void modify(ll l, ll r, ll val){
		for(l+=n, r+=n; l<r; l>>=1, r>>=1){
			if(l&1) t[l++]+=val;
			if(r&1) t[--r]+=val;
		}
	}
	inline void build(){
		IFR(i, n-1, 1) t[i]=Op(t[i<<1], t[i<<1|1]);
	}
	inline ll que(ll p){
		ll ans=0;
		for(p+=n; p; p>>=1) ans+=t[p];
		return ans;
	}
}st;
ll l[1<<20], r[1<<20];
vi v[1<<20];
int main(){
	fastio;
	ll n, m; cin>>n>>m;
	FER(i,0,n){
		cin>>l[i]>>r[i];
		v[r[i]-l[i]+1].pb(i);
	}
	ll ans=n, resp;
	st.n=m+1;
	FER(i,0,st.n) st.t[i+st.n]=0;
	st.build();
	cout<<n<<endl;
	FER(i,2,m+1){
		ans-=sz(v[i-1]);
		for(auto xd: v[i-1]) st.modify(l[xd], r[xd]+1, 1);
		resp=ans;
		for(ll j=i; j<=m; j+=i) resp+=st.que(j);
		cout<<resp<<endl;
	}
	return 0;
}
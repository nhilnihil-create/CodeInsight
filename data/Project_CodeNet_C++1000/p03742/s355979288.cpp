// #pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);
#define fou(i,a,n) for(int i=a;i<n;i++)
#define fod(i,a,n) for(int i=n-1;i>=a;i--)
#define rep(n) fou(_,0,n)
#define tra(a,x) for(auto& a : x)
#define elif(c) else if(c)
#define VI vector<int>
#define VD vector<double>
#define VC vector<char>
#define VS vector<string>
#define VVI vector<VI>
#define VVD vector<VD>
#define VVC vector<VC>
#define VVS vector<VS>
#define emb emplace_back
#define pub push_back
#define pob pop_back
#define mp make_pair
#define fi first
#define se second
#define si(vec) ((int)(vec).size())
#define all(vec) vec.begin(),vec.end()
#define lla(vec) vec.rbegin(),vec.rend()
#define range(vec,x,y) vec.begin()+x,vec.begin()+y
#define sortup(vec) sort(all(vec))
#define sortdown(vec) sort(lla(vec))
#define eraseif(vec,condition_x) vec.erase(remove_if(all(vec),[](auto x){return condition_x;}),vec.end())
#define countif(vec,condition_x) count_if(all(vec),[](auto x){return condition_x;})
#define replaceif(vec,condition_x,n) replace_if(all(vec),[](auto x){return condition_x;},n)
#define optvalue(vec,condition_x,relation_x_opt) *min_element(all(vec),[](int x,int opt){return condition_x ? (opt==0)||!(relation_x_opt):false;})
#define erase_unique(vec) vec.erase(unique(all(vec)),vec.end())
#define calcvec(vec,calc_x) for_each(all(vec),[](int&x){x= calc_x;})
#define calc2vec(vec1,op,vec2) {rep(1){int s=min(si(vec1),si(vec2));fou(i,0,s)vec1[i]=vec1[i] op vec2[i];}}
template<class C>void mini(C &a,C b){a=min(a,b);}
template<class C>void maxi(C &a,C b){a=max(a,b);}
#define in(T,...) T __VA_ARGS__;_cin(__VA_ARGS__);
#define out(...) _cout(__VA_ARGS__);
void _cin(){}template<class Head,class...Tail>void _cin(Head&head,Tail&&...tail){cin>>head;_cin(forward<Tail>(tail)...);}
template<class Head>void _cout(Head head){cout<<head<<endl;}template<class Head,class...Tail>void _cout(Head head,Tail...tail){cout<<head<<" ";_cout(forward<Tail>(tail)...);}
template<class C>void outvec(vector<C> vec){int vecsize=si(vec);fou(i,0,vecsize-1)cout<<vec[i]<<" ";out(vec[vecsize-1]);}
template<class C> C gcd(C a,C b){if(a&&b)return gcd(min(a,b),max(a,b)%min(a,b));else return a;}
template<class C> C lcm(C a,C b){return a/gcd(a,b)*b;}




#define int int64_t
// #define double long double


// 無名関数template
// map,makepair

signed main(){
  IOS;

  in(int,x,y)
  string ans;
  ans= (abs(x-y)<=1) ? "Brown" : "Alice";
  out(ans);


}
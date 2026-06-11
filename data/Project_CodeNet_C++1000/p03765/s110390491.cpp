#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  string s,t;
  cin >> s >> t;
  int ns=s.size();
  int nt=t.size();
  int csa[ns+1],cta[nt+1];
  int csb[ns+1],ctb[nt+1];

  csa[0]=cta[0]=csb[0]=ctb[0]=0;
  rep1(i,ns){
    csa[i]=csa[i-1];
    csb[i]=csb[i-1];
    if(s[i-1]=='A') csa[i]++;
    else csb[i]++;
  }

  rep1(i,nt){
    cta[i]=cta[i-1];
    ctb[i]=ctb[i-1];
    if(t[i-1]=='A') cta[i]++;
    else ctb[i]++;
  }
   
  int q;
  cin >> q;
  int a[q],b[q],c[q],d[q];
  rep(i,q){
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    a[i]--;b[i]--;
    c[i]--;d[i]--;
  }
  //  rep(i,nt+1) cout << ctb[i] << endl;
  //  cout << "  "<< endl;
  rep(i,q){
    int tmp_cs =  (csa[b[i]+1]-csa[a[i]])%3;
    tmp_cs += (((csb[b[i]+1]-csb[a[i]])%3)*2)%3;
    tmp_cs %=3;
    int tmp_ct =  (cta[d[i]+1]-cta[c[i]])%3;
    tmp_ct += (((ctb[d[i]+1]-ctb[c[i]])%3)*2)%3;
    tmp_ct %=3;
    //    cout << tmp_cs << " " <<tmp_ct << endl;
    if(tmp_cs==tmp_ct)cout << "YES" << endl;
    else cout << "NO" << endl;
  }

  return 0;

}

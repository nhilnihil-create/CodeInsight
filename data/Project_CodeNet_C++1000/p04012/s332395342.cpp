///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
#define     int 	    long long
#define 	pb 	        push_back
#define 	mp 	        make_pair
#define 	pi 	        2*acos(0.0)
#define     scan(i)     scanf("%d",&i)
#define     loop(i,n) 	for(int i = 0 ; i <n ; i++)
#define 	vect 	    vector<int>
#define 	vec_it 	    vector<int>::iterator vi
#define     sorta(v)    sort(v.begin(),v.end())
#define     sortd(v)    sort(v.begin(),v.end(),greater<>())
#define 	mapp 	    map<char,int>
#define 	pairr 	    pair<int,int>
#define 	sett	    set<int>s
#define 	set_it 	    set<int>::iterator si
#define     map_it      map<char,int> :: iterator mi
#define 	yes 	    cout<<"Yes"<<endl
#define 	no 	        cout<<"No"<<endl
#define 	ff 	        first
#define 	ss 	        second
#define     mx          iNT_MAX
#define     lmx         LLONG_MAX
#define     mn          iNT_MiN
#define     lmn         LLONG_MiN
#define     GCD         __gcd(a,b)
#define     LCM         (a/GCD)*b
template <typename T> T gcd(T a,T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a,T b) {return a*(b/gcd(a,b));}
int modulo (int a, int b) { return a >= 0 ? a % b : ( b - abs ( a%b ) ) % b; }

void solve()
{
  // freopen ("(input).txt" , "r",  stdin) ;
   string st,stt ;
  // int low=0,high=0;
  // int l,r;
    int n,k,t,b,c,x,y,z,d=0,temp=0,cnt=0,sum=0,f=0;
    cin>>st;  ; vect v ,a  ; sett ; set_it ; mapp m,mp; pairr p; map_it;
    loop(i,st.size())
    {
        m[st[i]]++;
    }
    for(mi=m.begin();mi!=m.end();mi++)
    {
        temp=mi->ss;
        if(temp&1)
            cnt=1;
    }
    if(cnt==0)
        yes;
    else
        no;


}

main()
{
    int t;
  //  cin>>t;
  //  while(t--)
        solve();
}
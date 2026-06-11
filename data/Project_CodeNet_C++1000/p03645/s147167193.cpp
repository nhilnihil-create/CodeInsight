///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
#define     FAST        ios_base::sync_with_stdio(false);cin.tie(NULL)
#define     int 	    long long
#define 	pb 	        push_back
#define 	mp 	        make_pair
#define 	pi 	        2*acos(0.0)
#define     scan(i)     scanf("%lld",&i)
#define     scann(i,j)  scanf("%lld%lld",&i,&j)
#define     print(i)    printf("%lld\n",i)
#define     printt(i,j) printf("%lld %lld\n",i,j)
#define     loop(i,n) 	for(int i = 0 ; i <n ; i++)
#define     loopp(i,n) 	for(int i = 1 ; i <=n ; i++)
#define 	vect 	    vector<int>
#define 	vec_it 	    vector<int>::reverse_iterator vi
#define     sorta(v)    sort(v.begin(),v.end())
#define     sortd(v)    sort(v.begin(),v.end(),greater<>())
#define     sorted      is_sorted(v.begin(),v.end())
#define 	mapp 	    map<int,int>
#define 	pairr 	    pair<int,int>
#define 	sett	    set<int>
#define 	set_it 	    set<int>::reverse_iterator si
#define     map_it      map<int,int> :: reverse_iterator mi
#define 	yes 	    cout<<"YES"<<endl
#define 	no 	        cout<<"NO"<<endl
#define 	ff 	        first
#define 	ss 	        second
#define     mx          INT_MAX
#define     lmx         LLONG_MAX
#define     mn          INT_MIN
#define     lmn         LLONG_MIN
#define     GCD         __gcd(a,b)
#define     LCM         (a/GCD)*b
template <typename T> T gcd(T a,T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a,T b) {return a*(b/gcd(a,b));}
int modulo (int a, int b) { return a >= 0 ? a % b : ( b - abs ( a%b ) ) % b; }

void solve()
{
  //  freopen ("(input).txt" , "r",  stdin) ;
  //  string st,stt ;
  //  int low=0,high=0;
  //  int l=0,r;
    int n,k,t,x,y,z,d=0,temp=0,cnt=0,sum=0,f=0;
    cin>>n>>k  ; vect v ,a ,b  ; sett s ; set_it ; mapp m,mm ;  map_it ; pairr p[k] ;
    loop(i,k)
    {
        cin>>p[i].ff>>p[i].ss;
        if(p[i].ff==1)
            m[p[i].ss]++;
    }
    loop(i,k)
    {
        if(m[p[i].ff]>0&&p[i].ss==n)
        {
            temp=1;break;
        }

    }
    if(temp==1)
        cout<<"POSSIBLE"<<endl;
    else
        cout<<"IMPOSSIBLE"<<endl;


}

main()
{
    int t;
  //  cin>>t;
  //  while(t--)
        solve();
}
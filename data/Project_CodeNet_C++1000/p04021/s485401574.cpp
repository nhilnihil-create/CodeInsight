/********************************************************************
   . . . . . . . . .
   . . . . . . . . .
   . . . . . . . . .
   . . . . . . . . .                                                  IIIIIII
   . . . . . . . . . . . .                                               I    n
   . . . . . . . . . . . .                                               I    n n n
   . . . . . . . . . . . .                                               I    n   n
   . . . . . . . . . . . .                                            IIIIIII n   n
  _____  . . . . . . . . .
 |     | . . . . . . . . .                                            TTTTTT h
 |     | . . . . . . . . .                                              T    h       eeee
 |     |_;_;_;_;_;_;_;_;_;_                                             T    h h h  eeeeee
 |     |     ___           |                                            T    h   h  e
 |     |    \   \__        |                         R R   K            T    h   h   eeeee
 |     |     \  #  \___    |                         R  R K
 |     |      \        \   |                         R R K             NN    N
 |     |       ---------   |                         R    K            N N   N   aaa    m         eeee
 |     |              ___  |                         R     K           N  N  N  a   a   m m m m  eeeeee
 |     |             \ O \ |                 ______________________    N   N N  a   a   m  m  m  e
 |     |              ---- |                 \                    |    N    NN   aaa a  m  m  m   eeeee
 |     |                   |                  \   $    20     $  |                    a
 |     |       %%%%%%%%%%%%|                   \   King  Reza   |
 |     |       %%%%%%%%%%%%|                    \____      ____|         O        f f
 |     |       \___________|                        |     |            O   O     f
 |     |        \__________|                        |     |           O     O  f f f
 |     |                    ---------------         |     |            O   O    f
 |     |                                 _|         |     |              O     f
 |     |                                |           |     |
 |     |         -----------------------            |     |            @    G G G      O     D D    @
 |     |        |                                   |     |           @    G         O   O   D  D    @
 |     |        |                                   |     |          @    G   G G   O     O  D   D    @
 |     |        |                                   |     |           @    G     G   O   O   D  D    @
 |     |        |                                   |     |            @    G G G      O     D D    @
 |     |        ------------------------------------      |
 |     |                                                  |
 |     |                                                  |
 |     |        ------------------------------------------
 |     |        |
 |     |        |
 |     |        |
 |     |        |
 |     |        |
 |     |        |
 |     |        ------------------------------------------
 |     |                                                  |
 |     |                                                  |
 |     |--------------------------------------------      |
 |     |                                            |     |
 |     |                                            |     |
 |     |                                            |     |
 |     |                                            |     |
 |     |                                            |     |
 |     |                                            |     |
 |     |                                            |     |
 |     |                                            |     |
 |     |                                            |     |
 |     |                                            |     |
 |     |                                            |     |
 |     |                                           |       \
 |     |                                          |         \
 |     |                                         |           \
 |_____|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


************************************************************************/

#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define pb push_back
#define in insert
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define debug(x) cerr<<#x<<" : "<<x<<endl
#define txtin freopen("input.txt","r",stdin)
#define txtout freopen("output.txt","w",stdout)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define forup(i,x,y) for(int i=(x);i<=(y);i++)
#define fordo(i,x,y) for(int i=(x);i>=(y);i--)
#define forit(x) for(auto it=x.begin();it!=x.end();it++)
#define pqi priority_queue<int>
#define pql priority_queue<ll>
#define npqi priority_queue<int,vector<int>,greater<int> >
#define npql priority_queue<ll,vector<ll>,greater<ll> >
#define no cout<<"NO"<<endl;
#define yes cout<<"YES"<<endl;
#define p2(n) (1ll<<(n))
#define migmig ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define sz(x) (int)x.size()

using namespace std;

ll Log=30;
const ll mod=(ll)1e9+7;
const ll inf=(ll)2242545357980376863;
const int e6=1e6;
const int e2_5=2e5;
const int M=1e6+20;
const int N=2e5+20;

int n,a[N],b[N],sum;
int main(){
	migmig;
	cin>>n;
	forup(i,0,n-1){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b,b+n);
	for(int i=0;i<n;i+=2){
		if ((lower_bound(b,b+n,a[i])-a)%2){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}


















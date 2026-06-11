



#include<bits/stdc++.h>
using namespace std;



//defines...
#define ll long long
#define tata return;
#define pb push_back
#define mp make_pair
#define in insert
#define run ios_base::sync_with_stdio(false);cin.tie(NULL);
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define vec vector<ll>
#define setl set<ll>
#define mapl map<ll,ll>
#define shunno cout<<0<<endl;
#define pi 2*acos(0.0)1
#define hobena cout<<-1<<endl;




//typedefs...
typedef pair<ll,ll>pll;

//const..
const ll fx[]={0,1,0,-1};
const ll fy[]={1,0,-1,0};
const ll mod=1e9+7;

/*ll ncr(ll n, ll k)
{
    ll res = 1;


    if (k > n - k)
        k = n - k;

    for (int i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}
*/
//to remove suffix of a number from a set of string
/*
for(int k=1; k<j.size(); k++)
                if(temp.count(string(j.begin()+k,j.end())))
					temp.erase(string(j.begin()+k,j.end()));
 */

void oka()
{
   ll n,i,j;

   cin>>n;
   ll a[n];
   for(i=0;i<n;i++)
    cin>>a[i];
   sort(a,a+n);
   mapl m;
   vec v;
   for(i=0;i<n;i++)
   {
       m[a[i]]++;
       if(m[a[i]]%2==0)
            v.pb(a[i]);

   }
   for(i=0;i<v.size();i++)
    v[i]*=-1;
   if(v.size()<2)
   {
       shunno
       tata
   }
   sort(v.begin(),v.end());
    for(i=0;i<v.size();i++)
    v[i]*=-1;

   ll ans=1;
   for(i=0;i<2;i++)
    ans*=v[i];
   cout<<ans<<endl;





}
/*I'll paint it on the walls
     cause I'm the one at fault
    I'll never fight again and
         this is how it ends .*/






int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    run

    oka();




}
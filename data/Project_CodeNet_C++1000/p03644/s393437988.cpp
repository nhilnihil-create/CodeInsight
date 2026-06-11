/*
                IftekharMd.Shishir
                Dept. of Information and Communication Engineering
                University of Rajshahi
*/

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>

#define ll  long long
#define ull  unsigned long long
#define ld  long double
#define f(i,n)  for(i=0;i<n;i++)
#define F(i,n)  for(i=n-1;i>=0;i--)
#define fa(i,a,b)  for(i=a;i<=b;i++)
#define Fa(i,a,b)  for(i=a;i>=b;i--)
#define printArray(i,a,n)  f(i,n)cout<<a[i]<<" "; cout<<endl;
#define printSet(a)  for(auto setData:a) cout<<setData<<" ";cout<<endl;
#define printMap(a)  for(auto mapData:a) cout<<mapData.first<<" "<<mapData.second<<endl;
#define printVector(a)  for(auto vectorData:a)cout<<vectorData<<" ";cout<<endl;
#define printLinkedList()  temp=head;while(temp){cout<<temp->data<<" ";temp=temp->post;} cout<<endl;

#define pb(x)  push_back(x)
#define all(a)  a.begin(),a.end()
#define rall(a)  a.rbegin(),a.rend()

#define bs  binary_search
#define lb  lower_bound
#define ub  upper_bound
#define mp  make_pair
#define TxtIO  freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define TxtTest freopen("C:/Users/Iftekhar/Documents/what/input.txt", "r", stdin);
#define FastIO  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define TestCase  ll t;cin>>t;while(t--)
#define points(x)  fixed<<setprecision(x)
#define scd(a,x,y)  a/__gcd(x,y);
#define nl  cout<<endl;
#define done  return 0

const ld PI= 3.14159265358979323846264338327950288;  //2*acos(0.0);
const long long MOD= 1000000007;
const long long MAX = 32000;

// stringstream demo(str);  demo >> x;
// stringstream demo;  demo << x;  name=demo.str();

using namespace __gnu_pbds;
using namespace std;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

int main()
{
        FastIO;
        //TxtTest;
        ll n,i;
        cin>>n;
        if(n==1) {
                cout<<1<<endl;
                done;
        }
        ll a[7]={2,4,8,16,32,64,128};
        for(i=0;i<7-1;i++){
                if(n>=a[i] && n<a[i+1]){
                        cout<< a[i] <<endl;
                        done;
                }
        }
        done;
}



#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define input_txt() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define si set<int>
#define msi map<string, int>
#define test ll t; cin>>t; while(t--)
#define input(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define sqr(a) (a)*(a)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
const double PI = acos(-1);
const int inf=2000000000;
const ll infLL=9000000000000000000;


void case_i()
{
    int x,y;cin>>x>>y;
    if((x==4 || x==6 || x==9 || x==11) && (y==4 || y==6 || y==9 || y==11) && x!=y)
        cout<<"Yes"<<endl;
    else if(x==2 || y==2)
        cout<<"No"<<endl;
    else if((x==1 || x==3 || x==5 || x==7 || x==8 || x==10 || x==12) && (y==1 || y==3 || y==5 || y==7 || y==8 || y==10 || y==12) && x!=y)
        cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

}

int main()
{
    IOS;
    //    input_txt();
    //test
    case_i();
    /**/
    return 0;
}



//End up here once more;





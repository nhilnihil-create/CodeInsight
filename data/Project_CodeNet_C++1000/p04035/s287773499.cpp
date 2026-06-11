///-----Bismillahir Rahmanir Rahim-----///

#include<bits/stdc++.h>
using namespace std;

///---FAST I/O---///
#define Boost() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

///---DATA TYPE---///
typedef long long ll;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<int>::iterator vit;
typedef set<int>::iterator sit;

///---LOOP---///
#define rep0(i,n) for(i=0;i<n;i++)
#define rep1(i,n) for(i=1;i<=n;i++)

///---I/O---///
#define sf scanf
#define pf printf

///---OTHERS---///
#define pb push_back
#define all(c)		c.begin(),c.end()
#define MK make_pair
#define F first
#define S second
#define endl '\n'


///---INITIALIZATION---//
#define mem(a,b) memset(a, b, sizeof(a) )

///---CALCULATE---///
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define sqr(a) ((a) * (a))

///---BIT OPERATION---///
inline bool checkBit(ll n, int i)
{
    return n&(1LL<<i);
}
inline ll setBit(ll n, int i)
{
    return n|(1LL<<i);;
}
inline ll resetBit(ll n, int i)
{
    return n&(~(1LL<<i));
}

///------String/Char Related Functions-----///
string makeintString(int x)
{
    stringstream ss;
    ss << x;
    string str = ss.str();
    ///cout<<str<<endl;
    return str;
}
string makellString(ll x)
{
    stringstream ss;
    ss << x;
    string str = ss.str();
    ///cout<<str<<endl;
    return str;
}
char cpp(char c)
{
    return static_cast<char>(c + 1);
}

///------------Sorting STL----------///
struct func
{
    //this is a sample overloading function for sorting stl
    bool operator()(pii const &a, pii const &b)
    {
        if(a.F==b.F)
            return (a.S<b.S);
        return (a.F<b.F);
    }
};

///---CONSTANT---///
const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
#define MOD 1000000007

int main()
{
    Boost();

    int t;
    t=1;
    //cin>>t;
    while(t--)
    {
        ll n,l,x;
        cin>>n>>l;
        vector<ll>a;
//        ll sum=0;
        for(ll i=0; i<n; i++)
        {
            cin>>x;
//            sum+=x;
            a.pb(x);
//            b.pb(x);
        }
        if(n==2)
        {
            if(a[0]+a[1]>=l)
            {
                cout<<"Possible"<<endl<<"1"<<endl;
            }
            else
            {
                cout<<"Impossible"<<endl;
            }
            return 0;
        }
        //vector<ll>ans1;

        ll flag1=-1;
        for(ll i=0; i<n-1; i++)
        {
            if(a[i]+a[i+1]>=l)
            {
                //ans1.pb(i+1);
                flag1=i+1;
                break;
            }
        }
        if(flag1!=-1)
        {
            cout<<"Possible"<<endl;
            for(ll i=1; i<flag1; i++)
            {
                cout<<i<<endl;
            }
            for(ll i=n-1; i>=flag1; i--)
            {
                cout<<i<<endl;
            }
        }
        else
        {
            cout<<"Impossible"<<endl;
        }

//
//        for(ll i=n-1; i>=2; i--)
//        {
//            if(a[i-1]+a[i-2]>=l)
//            {
//                ans2.pb(i);
//            }
//            else
//            {
//                flag2=1;
//                break;
//            }
//        }
//        if(flag2==0)
//        {
//            if(a[0]+a[1]<l)
//            {
//                flag2=1;
//            }
//            else
//            {
//                ans2.pb(1);
//            }
//        }
//
//        if(flag1==1 && flag2==1)
//        {
//            cout<<"Impossible"<<endl;
//        }
//        else if(flag1==0)
//        {
//            cout<<"Possible"<<endl;
//            for(ll i=0; i<ans1.size(); i++)
//            {
//                cout<<ans1[i]+1<<endl;
//            }
//        }
//        else if(flag2==0)
//        {
//            cout<<"Possible"<<endl;
//            for(ll i=0; i<ans2.size(); i++)
//            {
//                cout<<ans2[i]<<endl;
//            }
//        }
//    }

    }
    return 0;
}


/*

vector<ll>ans;
        ll flag=0;
        ll cnt=0;
        ll left=1,right=n-1;
        while(1)
        {
            vector<ll>::iterator it;
            if(a.size()<2)
            {
                break;
            }
            else if(sum>=l)
            {
               // cout<<a[0]<<" "<<a[a.size()-1]<<endl;
                if(a[0]<a[a.size()-1])
                {
                    sum-=a[0];
                    it=a.begin();
                    a.erase(it);
                    ans.pb(left);
                    left++;
                }
                else
                {
                    sum-=a[a.size()-1];
                    it=(a.end()-1);
                    a.erase(it);
                    ans.pb(right);
                    right--;
                }
//                cout<<ans[0]<<" "<<sum<<endl;
//                cout<<"------------"<<endl;
            }
            else
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            cout<<"Impossible"<<endl;
        }
        else
        {
            cout<<"Possible"<<endl;
            for(ll i=0;i<ans.size();i++)
            {
                cout<<ans[i]<<endl;
            }
        }




*/

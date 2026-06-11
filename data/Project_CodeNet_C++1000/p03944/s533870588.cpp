//***********************************************__gamebred__**********************************************************
//OWNER: Dhruv Sharma BITSG


#include<bits/stdc++.h>
#include<cmath>
#define M 1000000007
#define ll long long
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define fi first
#define se second
#define loop(n) for(ll i=0;i<n;i++)
#define loop1(n) for(ll i=1;i<=n;i++)
#define looprev(n) for(ll i=n-1;i>=0;i--)
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

//use __gcd for gcd stupid!

bool sortinrev(const pair<ll,ll> &a,const pair<ll,ll> &b)
{
    if(a.first==b.first)
    {
        return (a.second>b.second);
    }
       return (a.first > b.first);
}
ll negmod(ll a, ll b)
{
    return (a%b+b)%b;
}
void LPS(string pattern, ll m, ll lps[])
{
    ll len = 0;
    lps[0] = 0;
    ll i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
int kmp(string pattern, string text)
{
    ll m = pattern.size();
    ll n = text.size();
    ll lps[m];
    LPS(pattern,m,lps);

    ll i = 0;
    ll j = 0;
    while (i < n)
    {
        if (pattern[j] == text[i])
        {
            j++;
            i++;
        }

        if (j == m)
        {
            //printf("Found pattern at index %d ", i - j);
            j = lps[j - 1];
            return 1;
        }

        else if (i < n && pattern[j] != text[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return 0;
}
int check(string s,int len)
{
    loop(s.size())
    {
        if(s[i]!=s[i%len])
            return false;
    }
    return true;
}
ll countdistinct(string s)
{
    int arr[200]={0};
    ll ans=0;
    loop(s.size())
    {
        arr[s[i]-' ']++;
    }
    loop(200)
    {
        if(arr[i]>=1)
            ans++;
    }
    return ans;
}
ll fastpow(ll base,ll exp)
{
    if (exp == 0)
        return 1;

    if (exp == 1)
        return base % M;

    ll t = fastpow(base, exp / 2);
    t = (t * t) % M;

    if (exp % 2 == 0)
        return t;

    else
        return ((base % M) * t) % M;
}
bool isprime(ll num)
{
    bool flag=true;
    for(ll i = 2; i*i<=num; i++) {
       if(num % i == 0) {
          flag = false;
          break;
       }
    }
    return flag;
}
ll findXOR(ll n)
{
    ll mod = n % 4;

    if (mod == 0)
        return n;
    else if (mod == 1)
        return 1;
    else if (mod == 2)
        return n + 1;
    else if (mod == 3)
        return 0;
}
int main()
{
        fastio();
        ll t=1,n,m=0,k=0,p,q,l,r,e,h,w,count1=0,maxx=LLONG_MIN,sum=0,a=0,b,c,d,reqs,minn=LLONG_MAX,minn1=LLONG_MAX,x,y,time=0;
        vector<ll>::iterator ip;
        //cin>>t;
        map <string,ll> mh;
        while(t--)
        {
           sum=0,count1=0;
           minn=minn1=LLONG_MAX;
           maxx=LLONG_MIN;
           vector <ll> v,v1,v2,v3,v4,v5,v6;
           vector < pair <string,ll> > v7;
           string str,str1,str2;
           set <ll> s,s1;
           map <ll,ll> ss;
           vector <string> v8,v9;
           ll curr=0,curr1=0,prev=0;
           cin>>w>>h>>n;
           ll left=0;
           ll right=w;
           ll top=h;
           ll bottom=0;
           loop(n)
           {
               cin>>x>>y>>a;
               if(a==1 || a==2)
               {
                   if(a==1 && left<x)
                   left=x;
                   if(a==2 && right>x)
                    right=x;
                   continue;
               }
               if(a==3 || a==4)
               {
                   if(a==3 && bottom<y)
                   bottom=y;
                   if(a==4 && top>y)
                   top=y;
                   continue;
               }
           }
         // cout<<left<<" "<<right<<" "<<top<<" "<<bottom<<endl;
           //cout<<abs(right-left)*abs(top-bottom)<<endl;
           if(left>=right || top<=bottom)
            cout<<0<<endl;
           else if(right-left>0 && top-bottom>0)
            cout<<(right-left)*(top-bottom)<<endl;

        }

}


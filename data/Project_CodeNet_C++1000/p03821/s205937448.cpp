
/**Which of the favors of your Lord will you deny ?**/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define MP make_pair
#define F first
#define S second
#define INF INT_MAX

#define ALL(x) (x).begin(), (x).end()
#define DBG(x) cerr << __LINE__ << " says: " << #x << " = " << (x) << endl

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class TIn>
using indexed_set = tree<
                    TIn, null_type, less<TIn>,
                    rb_tree_tag, tree_order_statistics_node_update>;

/*
PBDS
-------------------------------------------------
1) insert(value)
2) erase(value)
3) order_of_key(value) // 0 based indexing
4) *find_by_order(position) // 0 based indexing

*/

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 2e5+7;
const LL LINF = 1e17;

string to_str(LL x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

//bool cmp(const PII &A,const PII &B)
//{
//
//}

LL a[nmax];
LL b[nmax];

LL BIT[nmax];
void update(int index,int val,int len)
{
    while(index<=len)
    {
        BIT[index] = BIT[index]+val;
        index += index&(-index);
    }
}

LL query(int index)
{
    LL sum=0;
    while(index>0)
    {
        sum = sum+BIT[index];
        index -= index&(-index);
    }
    return sum;
}

int main()
{
    optimizeIO();

    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        update(i,a[i],n);
        update(i+1,-a[i],n);
    }

    LL ans = 0;


    for(int i=n;i>=1;i--)
    {
        LL aa = query(i);

        if(aa%b[i]==0) continue;


        LL mul = aa/b[i] + 1;
        LL target = b[i]*mul;
        LL add = target - aa;
        ans += add;

        int l = 1,r =i;
        update(l,add,n);
        update(r+1,-add,n);
    }

    cout<<ans<<endl;

    return 0;
}



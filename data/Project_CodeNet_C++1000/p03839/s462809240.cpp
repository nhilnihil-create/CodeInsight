#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,a,b) for(int i=a;i<b;i++)
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define vi vector<int>
#define vv vector<vi>
#define pb push_back
#define pi pair<int,int>
#define vp vector<pair<int,int> >
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define INF 100000000000
#define eps 1e-7
#define mod 1000000007
#define int ll
using namespace std;

int N, K;
int a[100000+10];
int S[100000+10];
int positiveS[100000+10];

signed main(void) {
    cin>>N>>K;
    int positive_sum=0;
    rep(i, N) {
        cin>>a[i];
        if (i==0) {
            S[i]=a[i];
            if (a[i]>0) positiveS[i]=a[i];
            else positiveS[i]=0;
        } else {
            S[i]=S[i-1]+a[i];
            if (a[i]>0) positiveS[i]=positiveS[i-1]+a[i];
            else positiveS[i]=positiveS[i-1];
        }
    }

    int ans=0;
    REP(i, 0, N-K) {
//        cout<<"i:"<<i<<endl;
        //白で最後潰す場合
        int positive_sum_in_window = positiveS[K+i-1]-positiveS[i-1];
        int white = positiveS[N-1]-positive_sum_in_window;
//        cout << "positive_sum_in_window:" << positive_sum_in_window << endl;
//        cout << "white:" << white << endl;
        //黒で最後潰す場合
        int window_sum=S[K+i-1]-S[i-1];
        int black= white+window_sum;
//        cout << "window_sum:" << window_sum << endl;
//        cout << "black:" << black << endl;
        ans=max(ans, max(white, black));
    }
    cout<<ans<<endl;
    return 0;
}
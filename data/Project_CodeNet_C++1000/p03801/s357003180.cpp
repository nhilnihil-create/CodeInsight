/*ILTH      ILTH            ILTHILTHILTH    ILTH        ILTH
  ILTH      ILTH                ILTH        ILTH        ILTH
  ILTH      ILTH                ILTH        ILTHILTHILTHILTH
  ILTH      ILTH                ILTH        ILTH        ILTH
  ILTH      ILTHILTHILTH        ILTH        ILTH        ILTH

  */
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back

using namespace std;
typedef long long ll;
const int maxN=100005;

typedef pair<ll, int> pii;
ll n,ans[maxN];
pii a[maxN];
void sinhtest(){
    srand(time(0));
    ofstream cout("a.inp");
    cout << "10\n";
    for (int i=1; i<=10; ++i) cout << rand()%10+1 << " ";
}
int main()
{
    //sinhtest();
    //ifstream cin("a.inp");
    //ofstream cout("a.out");
    cin >> n;
    for (int i=1; i<=n; ++i){
        cin >> a[i].fi;
        a[i].se=i;
    }
    sort(a+1, a+n+1);
    int mins=n+1;
    for (int i=n; i>=1; --i){
        mins=min(mins,a[i].se);
        if (a[i].fi==a[i-1].fi) continue;
        ans[mins]+=(a[i].fi-a[i-1].fi)*(n-i+1);
    }
    for (int i=1; i<=n; ++i) cout << ans[i] << "\n";
    return 0;
}

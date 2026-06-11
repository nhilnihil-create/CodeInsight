#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue> 
#include <stack>
#include <set>
#include <list>

using namespace std;
typedef long long ll;
#define rep(i, s, e) for (int(i) = (s); (i) <= (e); ++(i))
#define all(x) x.begin(),x.end()


int main()
{
	int n; cin >> n;
	ll Tnow, Anow;
	Tnow = Anow = 1;
	rep(i, 1, n)
	{
		ll t, a; cin >> t >> a;
		ll Tcan1, Acan1, Tcan2, Acan2;
		Tcan1 = ((Tnow + t - 1) / t)*t;
		Acan1 = ((Tnow + t - 1) / t)*a;
		Tcan2 = ((Anow + a - 1) / a)*t;
		Acan2 = ((Anow + a - 1) / a)*a;
		if (Tcan1 < Tnow || Acan1 < Anow)Tnow = Tcan2, Anow = Acan2;
		else if (Tcan2 < Tnow || Acan2 < Anow)Tnow = Tcan1, Anow = Acan1;
		else Tnow = min(Tcan1, Tcan2), Anow = min(Acan1, Acan2);
	}
	cout << Tnow + Anow << endl;
}

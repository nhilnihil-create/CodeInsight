#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
using namespace std;
const int mod = 1000000007;
#define ll long long

int main()
{
	ll H, W, ans = mod, S;
	ll s1, s2, s3, row;
	cin >> H >> W;
	if (H % 3 == 0 || W % 3 == 0) {
		cout << 0 << endl;
	}
	else {
		//縦に割る
		row = (H + 1) / 3;
		s1 = row * W;
		s2 = (H - row) * (W / 2);
		s3 = (H - row) * (W - W / 2);
		S = max({ s1,s2,s3 }) - min({ s1,s2,s3 });
		ans = min(ans, S);
		//cout << s1 << " " << s2 << " " << s3 << " " << S << endl;

		//横に割る
		row = (W + 1) / 3;
		s1 = row * H;
		s2 = (W - row) * (H / 2);
		s3 = (W - row) * (H - H / 2);
		S = max({ s1,s2,s3 }) - min({ s1,s2,s3 });
		ans = min(ans, S);
		//cout << s1 << " " << s2 << " " << s3 << " " << S << endl;

		//縦に3つに割る
		row = (H + 1) / 3;
		s1 = row * W;
		s2 = ((H - row)/2) * W;
		s3 = ((H - row) - ((H - row) / 2)) * W;
		S = max({ s1,s2,s3 }) - min({ s1,s2,s3 });
		ans = min(S, ans);

		//横に3つに割る
		row = (W + 1) / 3;
		s1 = row * H;
		s2 = ((W - row) / 2) * H;
		s3 = ((W - row) - ((W - row) / 2)) * H;
		S = max({ s1,s2,s3 }) - min({ s1,s2,s3 });
		ans = min(S, ans);

		cout << ans << endl;
	}
}


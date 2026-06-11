#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

// 二項係数計算用配列
ll comb[51][51];

// パスカルの三角形を用いて二項係数を計算
void cal_comb(int N) {
	for (int i = 0; i <= N; ++i) {
		for(int j = 0; j <= i; ++j) {
			if (j == 0 || j == i) {
				comb[i][j] = 1;
			}
			else {
				comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
			}
		}
	}
}

int main()
{
    ll N, A, B;
    cin >> N >> A >> B;
    vector<ll> v(N);
    REP(i, N) cin >> v[i];
    sort(ALL(v));
    reverse(ALL(v));

    ll maxNum = v[0];
    ll maxCount = 1;
    for (int i = 1; i < N; ++i)
    {
        if (v[i] == maxNum)
        {
            maxCount++;
        }
        else
        {
            break;
        }
    }

    double ans = 0;
    ll sumNum = 0;
    REP(i, A) sumNum += v[i];
    ans = (double)sumNum / A;

    ll countAll = 0;
    if (maxCount < A)
    {
        int left = -1, right = -1;
        REP(i, N)
        {
            if (v[i] == v[A - 1]) 
            {
                if (left == -1) 
                {
                    left = i;
                }
            }
            else
            {
                if (left != -1) 
                {
                    right = i - 1;
                    break;
                }
            }
        }
        if (right == -1)
        {
            right = N - 1;
        }
        int a = right - left + 1;
        int b = A - 1 - left + 1;
        cal_comb(a);
        countAll = comb[a][b];
    }
    else
    {
        cal_comb(maxCount);
        for (int i = A; i <= min(B, maxCount); ++i)
        {
            countAll += comb[maxCount][i];
        }
    }
    
    cout << fixed;
    cout << setprecision(10) << ans << endl;
    cout << countAll << endl;
}

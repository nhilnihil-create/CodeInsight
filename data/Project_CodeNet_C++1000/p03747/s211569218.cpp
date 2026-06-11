#include <bits/stdc++.h>

using namespace std;
const string filename = "test";

#define int long long

int n, l, t;
map<int, int> cnt_val;
int x[100011], w[100011], pos[100011];
int ans[100011], p[200011];

int cal(int z) // Numbers of collisions between ant z and the others.
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (i != z && w[i] != w[z])
		{
			int d = 0;
			if (w[z] == 1 && w[i] == 2)
			{
				if (x[z] < x[i]) d = x[i] - x[z];
				else d = l - x[z] + x[i]; 	
			}
			else 
			{
				if (x[z] > x[i]) d = x[z] - x[i];
				else d = l - x[i] + x[z];
			}
			if (2 * t >= d)
				cnt += (1 + (t * 2 - d)/l);
		}
	return cnt;	
}

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen( (filename + ".inp").c_str(), "r", stdin);
	//freopen( (filename + ".out").c_str(), "w", stdout);

	cin >> n >> l >> t;
	vector<int> final_pos;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> w[i];
		if (w[i] == 1) 
			pos[i] = (x[i] + t)%l;
		else pos[i] = ((x[i] - t)%l + l)%l;
		cnt_val[pos[i]]++;
		final_pos.push_back(pos[i]);
	}
	sort(final_pos.begin(), final_pos.end());
	if (final_pos.back() == final_pos[0]) // All ants have the same ending
	{
		for (int i = 0; i < n; i++)
			cout << final_pos[0] << '\n';
		return 0;
	}

	for (int i = 0; i < 2*n; i++)
	{
		if (i < n) p[i] = i;
		else p[i] = i - n;
	}
	int s = -1;
	for (int i = 0; i < n; i++)
		if (cnt_val[pos[i]] == 1)
		{
			s = i;
			break;
		}
	//cerr << "S: " << s << '\n';
	int cnt = cal(s);
	int id = (s + cnt) % n;	
	if (w[s] == 2) id = ((s - cnt)%n + n)%n;
	//cerr << '?' << id << ' ' << pos[s] << '\n';
	// I'm so dumb, i just need to find the value of pos that is unique, lul
	// id is the index of the ant that its final pos is equal to pos[s]  
	// since we have the id, the final pos of 1 ant, we create the answer using the previous final_pos array
	for (int i = 0; i < final_pos.size(); i++)
		if (final_pos[i] == pos[s])
		{
			int cur = id;
			ans[cur] = pos[s];
			for (int j = (i + 1) % (int)(final_pos.size()); j != i; j = (j + 1) % (int)(final_pos.size()))
			{
				//cerr << '?' << final_pos[j] << '\n';
				cur++;
				//cerr << '!' << p[cur] << '\n';
				ans[p[cur]] = final_pos[j];
			}
		}
	for (int i = 0; i < n; i++)
		cout << ans[i] << '\n';
}
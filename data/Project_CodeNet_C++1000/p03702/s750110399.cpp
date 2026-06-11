#include <bits/stdc++.h>
using namespace std;
 
#define int long long int
 
const int mod = 1e9 + 7;
// const long double pi_2 = acos(0);
 
template <typename Type>
istream &operator>>(istream &in, vector<Type> &vec) {
    int n = vec.size();
    for (int i = 0; i < n; i++)
        in >> vec[i];
    return in;
}
template <typename Type>
ostream &operator<<(ostream &out, vector<Type> &vec) {
    for (auto val : vec)
        out << val << " ";
    return out;
}

int a, b, n;

int f(int x, vector<int> v)
{
	int dec = a - b;
	for(int i = 0;i < n;i++)
		v[i] = max(0ll, v[i] - x * b);
	int cnt = 0;
	for(int i = 0;i<n;i++)
		cnt += v[i] / dec + (bool)(v[i] % dec);
	return cnt <= x;
}

#undef int
int main()
{
#define int long long int
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>a>>b;
    vector<int> v(n);
    cin>>v;
    int l = 0, h = 1000000000;
    while(h - l > 1)
    {
    	int m = (l + h) / 2;
    	if(f(m, v))
    		h = m;
    	else
    		l = m;
    }
    cout<<h<<endl;
 
    return 0;
}
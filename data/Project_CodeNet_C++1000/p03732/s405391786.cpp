#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
    long long W;
	cin >> N >> W;
	long long w[N];
	int v[N];
	vector<int>v1, v2, v3, v4;
	cin >> w[0]>> v[0];
	v1.push_back(v[0]);
	for (int i=1; i<N; i++){
		cin >> w[i] >> v[i];
		if (w[i]==w[0]) v1.push_back(v[i]);
		else if (w[i]==w[0]+1) v2.push_back(v[i]);
		else if (w[i]==w[0]+2) v3.push_back(v[i]);
		else v4.push_back(v[i]);
	}
	sort(v1.begin(), v1.end()); reverse(v1.begin(), v1.end());
	sort(v2.begin(), v2.end()); reverse(v2.begin(), v2.end());
	sort(v3.begin(), v3.end()); reverse(v3.begin(), v3.end());
	sort(v4.begin(), v4.end()); reverse(v4.begin(), v4.end());
	//for (int i=0; i<v1.size(); i++) cout << v1[i] << " ";
	//for (int i=0; i<v2.size(); i++) cout << v2[i] << " ";
	//for (int i=0; i<v3.size(); i++) cout << v3[i] << " ";
	//for (int i=0; i<v4.size(); i++) cout << v4[i] << " ";
	long long z = 0;
	for (int i=0; i<=v1.size(); i++){
		for (int j=0; j<=v2.size(); j++){
			for (int k=0; k<=v3.size(); k++){
				for (int l=0; l<=v4.size(); l++){
					if (w[0]*i+(w[0]+1)*j+(w[0]+2)*k+(w[0]+3)*l<=W){
						long long sum = 0;
						for (int x=0; x<i; x++) sum+= v1[x];
						for (int x=0; x<j; x++) sum+= v2[x];
						for (int x=0; x<k; x++) sum+= v3[x];
						for (int x=0; x<l; x++) sum+= v4[x];
						z = max (z, sum);
					}
			
				}
			}
		}
	}
	cout << z << endl;
}

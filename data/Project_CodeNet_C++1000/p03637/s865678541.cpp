#include<iostream>
#include<cstdio>

using namespace std;
/*                                   法一  搜索+判断   TLM
int n;
bool flag = true;
int arr[100005];
bool visit[100005];
int result[100005];

bool Judge(int arr[]) {
	for (int i = 0; i < sizeof(arr) - 1; ++i) {
		if (arr[i] * arr[i + 1] % 4 != 0) {
			return false;
		}
	}
	return true;
}

void DFS(int count) {
	if (flag == false)return;
	if (count == n) {
		if (Judge(result)) {
			if (flag) {
				cout << "Yes" << endl;
				flag = false;
				return;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		if (visit[i] == 0) {
			visit[i] = 1;
			result[count] = arr[i];
			DFS(count + 1);
			visit[i] = 0;
		}
	}
}


int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	DFS(0);
	if (flag) {
		cout << "No" << endl;
	}
	return 0;
}*/




int main() {
	int n;
	int a1 = 0, a2 = 0, a4 = 0,temp;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> temp;
		if (temp % 4 == 0) a4++;
		else if (temp % 2 == 0) a2++;
		else a1++;
	}
	if (a2 == 0) {
		if (a1 > a4 + 1) {
			cout << "No" << endl;
			return 0;
		}
		else {
			cout << "Yes" << endl;
			return 0;
		}
	}
	else {
		if (a1 > a4) {
			cout << "No" << endl;
			return 0;
		}
		else {
			cout << "Yes" << endl;
			return 0;
		}
	}
	return 0;
}

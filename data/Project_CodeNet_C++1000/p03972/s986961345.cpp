#include<iostream>
 
using namespace std;
 
int L[100005], R[100005];
const int INF = 100000007;
 
void merge(int a[], int left, int mid, int right)
{
	int n1 = mid - left, n2 = right - mid;
	int i, j, k;
	for (i = 0; i < n1; i++)L[i] = a[left + i];
	for (i = 0; i < n2; i++)R[i] = a[mid + i];
	L[n1] = R[n2] = INF; i = j = 0;
	for (k = left; k < right; k++)
	{
		if (L[i] <= R[j])
		{
			a[k] = L[i];
			i++;
		}
		else
		{
			a[k] = R[j];
			j++;
		}
	}
	return;
}
 
void mergesort(int a[], int left, int right)
{
	if (left + 1 < right)
	{
		int mid = (left + right) / 2;
		mergesort(a, left, mid);
		mergesort(a, mid, right);
		merge(a, left, mid, right);
	}
}
 
int main()
{
	int w, h;
	cin >> w >> h;
	int* p = new int[w+1];
	int* q = new int[h+1];
	for (int i = 0; i < w; i++)cin >> p[i];
	for (int i = 0; i < h; i++)cin >> q[i];
	mergesort(p, 0, w);
	mergesort(q, 0, h);
	long sum = 0;
	int longp = w + 1;
	int longq = h + 1;
	p[w] = q[h] = 100000007;
	int s = 0, t = 0;
	while (s < w || t < h)
	{
		if (p[s] < q[t])
		{
			sum += 1L*longq*p[s];
			longp--; s++;
		}
		else
		{
			sum += 1L*longp*q[t];
			longq--; t++;
		}
	}
	cout << sum << endl;
	return 0;
}
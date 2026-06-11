#include <iostream>

using namespace std;

long long a[310][310],sum=0;

int main(){
    int i,j,k,n;
    cin >> n;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin >> a[i][j];
        	if(j<i)
            sum += a[i][j];
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<i;j++){
            for(k=0;k<n;k++){
            	if(j==k || k==i){
            		continue;
            	}
            	
                if(a[i][j] > a[i][k]+a[k][j]){
                    cout << -1 << endl;
                    return 0;
                }
            	
            	if(a[i][j] == a[i][k]+a[k][j]){
                    sum -= a[i][j];
            		break;
            		//cout <<i <<" " << j << " "<< k << endl;
                }
            }
        }
    }
    cout << sum << endl;
}

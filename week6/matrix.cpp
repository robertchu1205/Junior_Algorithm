#include <iostream>
using namespace std;
int main() {
int n=0;
cin >> n;
int m[n+1][n+1];
int a[n+1];
int j=0;
int q=0;
for(int i=0;i<n+1;i++) {
    cin >> a[i];
}
for(int i=0;i<n+1;i++) {
    for(int j=0;j<n+1;j++) {
        m[i][j]=0;
    }
}

for(int i=1;i<n+1;i++) {
    m[i][i]=0;
}
for(int l=2;l<n+1;l++) {
    for(int i=1;i<=n-l+1;i++) {
        j=i+l-1;
        m[i][j]=9999999;
        for(int k=i;k<=j-1;k++) {
                q=m[i][k]+m[k+1][j]+a[i-1]*a[k]*a[j];
                if(q<m[i][j]) {
                 m[i][j]=q;

                   }
        }
    }
}
//for(int i=0;i<n+1;i++) {
//    for(int j=0;j<n+1;j++) {
//        cout << m[i][j] << " ";
//    }
//    cout << endl;
//}
cout << m[1][j];
return 0;
}

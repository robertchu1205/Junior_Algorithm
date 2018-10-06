#include <iostream>
#include <string.h>
using namespace std;
int main() {
int data_num;
string x,y;
   int m,n;
//int b[m+1][n+1];
cin >> data_num;
for(int i=0;i<data_num;i++) {
    cin >> x;
    cin >> y;
    m=x.size();
    n=y.size();
    int c[m+1][n+1];
    for(int j=0;j<=m;j++) {
        c[j][0]=0;
    }
    for(int j=0;j<=n;j++) {
        c[0][j]=0;
    }
    for(int e=1;e<=m;e++) {
        for(int f=1;f<=n;f++) {
            if(x[e-1]==y[f-1]) {
                c[e][f]=c[e-1][f-1]+1;
           //     b[e][f]=1;
            }
            else if(c[e-1][f]>=c[e][f-1]) {
                c[e][f]=c[e-1][f];
            //    b[e][f]=2;
            }
            else {
                    c[e][f]=c[e][f-1];
           //     b[e][f]=3;
            }
        }
    }
//    for(int j=0;j<=m;j++) {
//            for(int h=0;h<=n;h++) {
//    cout << c[j][h] << " "; }  cout << endl;}
cout << c[m][n] << endl;
}
return 0;
}

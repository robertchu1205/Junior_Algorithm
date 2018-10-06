#include <iostream>
using namespace std;
int value(int maxw,int *w,int *v)
{
    int c[6][maxw+1];
    for(int x=0;x<=maxw;x++) {
        c[0][x]=0;
    }
    for(int y=1;y<=6;y++) {
        c[y][0]=0;
    }
    for(int i=1;i<=5;i++) {
        for(int j=1;j<=maxw;j++) {
            if(w[i-1]<=j) {
                if(v[i-1]+c[i-1][j-w[i-1]]>c[i-1][j]) {
                    c[i][j]=v[i-1]+c[i-1][j-w[i-1]];
                }
                else {
                    c[i][j]=c[i-1][j];
                }
            }
            else {
                c[i][j]=c[i-1][j];
            }
        }
    }

    return c[5][maxw];
}
int main() {
int datanum=0;
int maxweight=0;
int weight5[5];
int value5[5];
cin >> datanum;
for (int i=0;i<datanum;i++) {
        cin >> maxweight;
    for(int j=0;j<5;j++) {
        cin >> weight5[j];
    }
    for(int k=0;k<5;k++) {
        cin >> value5[k];
    }
    cout << value(maxweight,weight5,value5) << endl;
}
return 0;
}

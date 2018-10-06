#include <iostream>
using namespace std;
int mincost (string s1,string s2) {
       // cout << "sadaff" << endl;
        int x,y;
        int cost1,cost2,cost3,mini;
        x=s1.size();
        y=s2.size();
        int c[x+1][y+1];

        for(int i=0;i<=y;i++) {
            c[0][i]=i*3;
        }
        for(int i=1;i<=x;i++) {
            c[i][0]=i*2;
        }
        for(int i=1;i<=x;i++) {
            for(int j=1;j<=y;j++) {
                if(s1[i-1]==s2[j-1]) {
                    c[i][j]=c[i-1][j-1];
                }
                else {
                    mini=0;
                    cost1=c[i-1][j]+2;
                    cost2=c[i][j-1]+3;
                    cost3=c[i-1][j-1]+4;
                    if(cost1<cost2) { mini=cost1; }
                    else {
                        mini=cost2;
                    }
                    if(mini>cost3) {
                        mini=cost3;
                    }
                    c[i][j]=mini;
                }
            }
        }
//        for(int i=0;i<=x;i++) {
//            for(int j=0;j<=y;j++) {
//                cout << c[i][j] << " ";
//            }
//            cout << endl;
//        }
        return c[x][y];
}
int main() {
string string1,string2;
int datanum;
cin >> datanum;
for(int i=0;i<datanum;i++) {
        cin >> string1;
        cin >> string2;
        cout << mincost(string1,string2) << endl;
}
return 0;
}

#include <iostream>
using namespace std;
int compare2(int a,int b);
int compare3(int a,int b,int c);
int arr[8][3];
int count;
int stage=1;
int test_cost;
int cost=0;
int c_total;
int total=0;
int main() {
for (int i=0;i<8;i++) {
    for(int j=0;j<3;j++) {
        cin >> arr[i][j];
    }
}
while(stage<5) {
    if(stage==1) {
        if(arr[0][0]<arr[0][1]) {
            total=arr[0][0];
            cost=1;
        }
        else {
            total=arr[0][1];
            cost=2;
        }
        if(arr[0][2]<total) {
            total=arr[0][2];
            cost=3;
        }
    }
    else if(stage==2) {
            count=0;
        c_total=10000;
        for(int i=0;i<3;i++) {
            count++;
            for(int j=0;j<3;j++) {
                if(arr[0][i]+arr[count][j]<c_total) {
                        c_total=arr[0][i]+arr[count][j];
                        if(j==0) {
                            cost=4;
                        }
                        else if(j==1) {
                            cost=5;
                        }
                        else if(j==2) {
                            cost=6;
                        }
                }
            }
        }
        total=c_total;
    }
    else if(stage==3) {
        count=0;
        total=10000;
        for(int i=0;i<3;i++) {
            count++;
            for(int j=0;j<3;j++) {
                if(arr[0][i]+arr[count][j]<total) {
                        total=arr[0][i];
                        cost=count;
                }
            }
        }
        count=4;
        c_total=10000;
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                if(arr[cost][i]+arr[count][j]<c_total) {
                        c_total=arr[cost][i]+arr[count][j];
                        if(j==0) {
                            cost=7;
                        }
                        else if(j==1) {
                            cost=8;
                        }
                        else if(j==2) {
                            cost=9;
                        }
                }
            }
            count++;
        }
        total+=c_total;
    }
    else if(stage==4) {
            count=0;
        total=10000;
        for(int i=0;i<3;i++) {
            count++;
            for(int j=0;j<3;j++) {
                if(arr[0][i]+arr[count][j]<total) {
                        total=arr[0][i];
                        cost=count;
                }
            }
        }
        count=4;
        c_total=10000;
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                if(arr[cost][i]+arr[count][j]<c_total) {
                        c_total=arr[cost][i];
                        test_cost=count;
                }
            }
            count++;
        }
        total+=c_total;

        cost=test_cost;
        c_total=10000;
        for(int i=0;i<3;i++) {
                if(arr[cost][i]+arr[7][i]<c_total) {
                        c_total=arr[cost][i]+arr[7][i];
                }
        }
        total+=c_total;
        cost=10;
     //   cout << cost << " " << total << endl;
//        if(cost==7) {
//            total+=arr[7][0];
//        }
//        else if(cost==8) {
//            total+=arr[7][1];
//        }
//        else if(cost==9) {
//            total+=arr[7][2];
//        }
//        cost=10;
    }
    if(stage==4) {
        cout << cost << " " << total;
    }
    else {
    cout << cost << " " << total << endl;
    }
    stage++;
}
return 0;
}
int compare2(int a,int b) {
    int mini;
    if(a<b) {
        mini=a;
    }
    else {
        mini=b;
    }
    return mini;
}

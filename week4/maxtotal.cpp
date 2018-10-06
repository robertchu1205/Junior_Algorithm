#include <iostream>
using namespace std;
int max(int a[]);

int mtest;
int m;
int main() {
    int arr[10];
    int casenum;
    cin >> casenum;
    while(casenum>0) {
        for(int i=0;i<10;i++) {
           cin >> arr[i];
        }
  //      max(arr);
        cout << max(arr) << endl;
        casenum--;
    }
return 0;
}
int max (int a[]) {
    m=-100000;
    for(int i=0;i<10;i++) {
            mtest=0;
        for(int j=i;j<10;j++) {
            mtest+=a[j];
             if(mtest>m) {
                m=mtest;
               // break;
            }
        }
    }
    return m;
}

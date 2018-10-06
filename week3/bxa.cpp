#include <iostream>
#include <iomanip>
using namespace std;
double mul2(int i);
double temp;
long temp1;
int x,y;
long temp2;
int main() {
    int num;
    cin >> num;
    int arr1[num];
    int arr2[num];
    int c[num];
    for (int i=0;i<num;i++) {
        cin >> arr1[i] >> arr2[i];
    }
//    for(int i=0;i<num;i++) {
//            temp=mul2(arr1[i])+mul2(arr2[i]);
//            c[i]=1;
//            while(temp>10)
//            {
//                cout << temp << endl;
//                c[i]++;
//                temp=temp/10;
//            }
//    }
    for (int i=0;i<num;i++) {
    //        cout << mul2(i) << endl;
        cout << fixed << setprecision(0) << mul2(arr1[i])+mul2(arr2[i]);
        if(i<num-1) { cout << endl; }
    }
return 0;
}
double mul2(int i) {
    if (i==0) {
 //           cout << "x" << endl;
        return 1;
    }
    else if (i==1) {
//        cout << "y" << endl;
        return 2; }
   // else if (i==2) { return 4; }
    else if (i%2==0) {      //i=偶數
//        cout << "z" << endl;
      //  temp=mul2(i/2);
       // cout << temp << endl;
        return mul2(i/2)*mul2(i/2);
    }
    else {                  //i=奇數
//        cout << "zzz" << endl;
//        x=i-1;
//        y=i+1;
//        temp1=mul2(x/2);
//        cout << temp1 << endl;
//        temp2=mul2(y/2);
//        cout << temp2 << endl;
        return mul2(i-1)*mul2(1);
    }
}

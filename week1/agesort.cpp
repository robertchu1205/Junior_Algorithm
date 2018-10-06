#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int *age;
    age =new int[n];
    int temp;
    int shift;

    while(n!=0)
    {
        for(int i=0;i<n;i++)
        {
            cin >> age[i];
        }
        int left=0;
        int right=n-1;
        while(left!=right) {
            for(int i=left;i<right;i++)
            {
                if(age[i]>age[i+1])
                    {
                        temp=age[i];
                        age[i]=age[i+1];
                        age[i+1]=temp;
                    }
                    shift=i;
            }
            right=shift;
            for(int i=right;i>left;i--)
            {
                if(age[i]<age[i-1])
                {

                        temp=age[i];
                        age[i]=age[i-1];
                        age[i-1]=temp;
                }
                shift=i;
            }
            left=shift;
        } /*
        for (int j=0;j<n-1;j++)
        {
            for(int i=0;i<n-1;i++)
            {
                if(age[i]>age[i+1])
                {
                        temp=age[i];
                        age[i]=age[i+1];
                        age[i+1]=temp;
                }
            }
        } */
        for(int i=0;i<n;i++)
        {
            if(i==n-1) {
                cout << age[i];
            }
            else {
            cout << age[i] << " "; }
        }
        cout << endl;
        cin >> n;
    }
    return 0;
}

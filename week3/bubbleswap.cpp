#include <iostream>
using namespace std;
int main()
{
    int n;
    int temp;
    int arr_n;
    int count=0;
    bool test=0;
    cin >> n;
    int num[50];
        for(int i=0;i<n;i++)
        {
            count=0;
            cin >> arr_n;
            for(int x=0;x<arr_n;x++) {
                cin >> num[x];
            }
             for (int j=0;j<arr_n-1;j++)
            {
                for(int i=0;i<arr_n-1;i++)
                {
                    if(num[i]>num[i+1])
                    {
                            temp=num[i];
                            num[i]=num[i+1];
                            num[i+1]=temp;
                            count++;
                    }
                }
            }
            cout << "Optimal swapping takes " << count << " swaps.";
            cout << endl;
        }
    return 0;
}

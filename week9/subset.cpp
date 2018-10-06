// http://www.geeksforgeeks.org/dynamic-programming-subset-sum-problem/
// A Dynamic Programming solution for subset sum problem
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

// Returns true if there is a subset of set[] with sun equal to given sum
bool isSubsetSum(vector<int> set, int n, int sum)
{
    // The value of subset[i][j] will be true if there is a
    // subset of set[0..j-1] with sum equal to i
    bool subset[sum+1][n+1];

    // If sum is 0, then answer is true
    for (int i = 0; i <= n; i++)
        subset[0][i] = true;

    // If sum is not 0 and set is empty, then answer is false
    for (int i = 1; i <= sum; i++)
        subset[i][0] = false;

    // Fill the subset table in botton up manner
    for (int i = 1; i <= sum; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            subset[i][j] = subset[i][j-1];
            if (i >= set[j-1])
                subset[i][j] = subset[i][j] ||
                               subset[i - set[j-1]][j-1];
        }
    }

    /* // uncomment this code to print table
     for (int i = 0; i <= sum; i++)
     {
       for (int j = 0; j <= n; j++)
          printf ("%4d", subset[i][j]);
       printf("\n");
     } */

    return subset[sum][n];
}

// Driver program to test above function
int main()
{
    int num = 1;
    cin >> num;
    cin.ignore();
    for (int i = 0; i < num; i++)
    {
        std::string input = "3 7 10 5 2 6 17 56;33";
        getline(cin, input);

        // find sum
        std::stringstream ss(input);
        std::string token;
        while (std::getline(ss, token, ';'))
        {
//    std::cout << token << '\n';
        }
        int sum;
        istringstream ( token ) >> sum;

        // find array
        vector<int> inputs;
        int tmp;
        stringstream ss2(input);
        char ch;
        while(ss2 >> tmp)
        {
            inputs.push_back(tmp);
        }

        // ans
        int n = inputs.size();//sizeof(set)/sizeof(set[0]);
        if (isSubsetSum(inputs, n, sum) == true)
        {
            cout << "True" << endl;
        }
        else
            cout << "False" << endl;
    }
    return 0;
}

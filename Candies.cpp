#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'candies' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY arr
 */

long candies(int n, vector<int> arr)
{
    vector<int> temp(n);
    int num = 1;

    for (int i = 1; i < n; ++i)
    {
        if (arr[i] > arr[i-1])
            num++;
        else if (arr[i] <= arr[i-1])
             num = 1;
        
        temp[i] = num;
    }

    num = 1;
    long count = temp[n-1];
    
    for (int i = n-2; i >= 0; --i)
    {
        if (arr[i] > arr[i+1])
            num++;
        else if (arr[i] <= arr[i+1])
            num = 1;
        
        if( num > temp[i])
            temp[i] = num;

        count += temp[i];
    }    
    
    return count;
}


#include<bits/stdc++.h>
using namespace std;
int kadane(int* arr,  int n)
{
    // initialize sum, maxSum and
    int sum = 0, maxSum = INT_MIN, i;

    // Just some initial value to check for all negative values case

    // local variable
    int local_start = 0;

    for (i = 0; i < n; ++i)
    {
        sum += arr[i];
        if (sum < 0)
        {
            sum = 0;
            local_start = i+1;
        }
        else if (sum > maxSum)
        {
            maxSum = sum;

        }
    }

     // There is at-least one non-negative number


    // Special Case: When all numbers in arr[] are negative
    maxSum = arr[0];

    // Find the maximum element in array
    for (i = 1; i < n; i++)
    {
        if (arr[i] > maxSum)
        {
            maxSum = arr[i];
        }
    }
    return maxSum;
}
int main()
{
    int r,c,n,k,ans=0;
    scanf("%d%d%d%d",&r,&c,&n,&k);
    int a[r][c];
    memset(a,0,sizeof a);
    int b,d;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&b,&d);
        a[b-1][d-1]=1;
    }
    //    for(int i=0;i<r;i++)
    //    {
    //        for(int j=0;j<c;j++)cout<<a[i][j];
    //        cout<<endl;
    //    }

    int left, right, i;
    int temp[r], sum;

    // Set the left column
    for (left = 0; left < c; ++left)
    {
        // Initialize all elements of temp as 0
        memset(temp, 0, sizeof(temp));

        // Set the right column for the left column set by outer loop
        for (right = left; right < c; ++right)
        {
            // Calculate sum between current left and right for every row 'i'
            for (i = 0; i < r; ++i)
                temp[i] += a[i][right];

            // Find the maximum sum subarray in temp[]. The kadane() function
            // also sets values of start and finish.  So 'sum' is sum of
            // rectangle between (start, left) and (finish, right) which is the
            //  maximum sum with boundary columns strictly as left and right.
            sum = kadane(temp, r);

            // Compare sum with maximum sum so far. If sum is more, then update
            // maxSum and other output values
            if (sum>=k)
            {
                ans++;
            }
        }
    }
    printf("%d",ans);
    return 0;



}


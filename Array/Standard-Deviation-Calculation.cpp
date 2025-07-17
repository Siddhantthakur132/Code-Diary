/*
📌 Program: Standard Deviation Calculation
📂 File Name: Standard-Deviation-Calculation.cpp

🧠 Approach:
1. Given a fixed array of 15 integers, we are calculating the **standard deviation**.
2. First, calculate the **mean** (average) of all elements.
3. Then, compute the sum of squares of differences between each element and the mean.
4. Finally, use the standard deviation formula:  
        σ = sqrt(Σ((xᵢ - μ)²) / n)
   where:
     - σ is the standard deviation
     - μ is the mean
     - xᵢ is each element
     - n is the number of elements

✅ Output: It will print the standard deviation value of the array.

🔧 Time Complexity: O(n) — as we iterate through the array twice.
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 15;

    vector<int> arr = { 5, 10, 15, 20, 25, 30, 35, 40,
                        45, 50, 55, 60, 65, 70, 75 };

    double mean, sum = 0.0, stdD = 0.0;

    // Calculate sum of elements to find mean
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    mean = sum / n;

    // Calculate sum of squared differences from the mean
    for (int i = 0; i < n; i++)
    {
        stdD += pow(arr[i] - mean, 2);
    }

    // Final standard deviation
    cout << sqrt(stdD / n);

    return 0;
}

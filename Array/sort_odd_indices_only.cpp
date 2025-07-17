/*
📌 Problem: Sort only the elements at odd indices in ascending order.
            Do NOT change the elements at even indices.

🧠 Approach:
1. Extract elements at odd indices into a temporary array.
2. Sort that temporary array.
3. Put the sorted values back at their original odd indices.

⏱️ Time Complexity:
- Extracting: O(n)
- Sorting: O(k log k), where k = number of odd indices ≈ n/2
- Inserting back: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);

    // Input the array
    cout << "Enter the array elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Step 1: Extract odd-indexed elements
    vector<int> oddElements;
    for (int i = 1; i < n; i += 2) {
        oddElements.push_back(arr[i]);
    }

    // Step 2: Sort the extracted elements
    sort(oddElements.begin(), oddElements.end());

    // Step 3: Put them back at odd positions
    int index = 0;
    for (int i = 1; i < n; i += 2) {
        arr[i] = oddElements[index++];
    }

    // Output the modified array
    cout << "Modified array:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

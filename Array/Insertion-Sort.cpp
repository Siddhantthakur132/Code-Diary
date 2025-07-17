/*
📌 Problem: Sort an array using Insertion Sort.

🧠 Approach:
1. Read the number of elements `n` and input the array.
2. Apply **Insertion Sort**:
   - Start from index 1 and pick each element (`k`).
   - Compare `k` with elements to its left (`arr[j]`).
   - Shift larger elements to the right until the correct position is found.
   - Insert `k` at its correct position.

⏱️ Time Complexity:
- Best Case: O(n)  — already sorted
- Worst Case: O(n^2) — reverse sorted

📥 Input:
- First line: Integer `n` (number of elements)
- Next line: `n` space-separated integers

📤 Output:
- Sorted array (space-separated)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n; // Input size of the array

    vector<int> arr(n);

    // Input array elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 🔁 Insertion Sort
    for (int i = 1; i < n; i++) {
        int k = arr[i];  // Current element to be inserted
        int j = i - 1;

        // Shift elements greater than `k` one position ahead
        while (j >= 0 && arr[j] > k) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        // Insert `k` at the right position
        arr[j + 1] = k;
    }

    // Output sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

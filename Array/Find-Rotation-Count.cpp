/*
📌 Problem: Find how many times a **sorted array** has been rotated.
This is equivalent to finding the **index of the minimum element**.

🧠 Approach:
1. Input the size `n` and the array elements.
2. Initialize `min_val` as INT_MAX and `min_idx` as 0.
3. Traverse the array:
   - If current element < `min_val`, update `min_val` and `min_idx`.
4. The index of the minimum element is the **rotation count (k)**.

💡 Note:
- Works for arrays **sorted in ascending order** and then rotated `k` times.
- Assumes no duplicate elements.

📥 Input:
- First line: Integer `n` (number of elements)
- Next `n` elements: Rotated sorted array

📤 Output:
- An integer `k`: number of rotations
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int n;
  cin >> n;

  vector<int> arr(n);

  // Input array
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int min_val = INT_MAX;
  int min_idx = 0;

  // Find index of minimum element (rotation count)
  for (int i = 0; i < n; i++) {
    if (arr[i] < min_val) {
      min_val = arr[i];
      min_idx = i;
    }
  }

  cout << min_idx;

  return 0;
}

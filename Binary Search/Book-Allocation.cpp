/*
Problem Name: Book Allocation Problem

Approach: Binary Search on Answer

Explanation:
- We are given an array `arr[]` of `n` integers where each element represents the number of pages in a book.
- We have to allocate books to `k` students such that:
  - Each student gets **at least one book**.
  - Each book should be allocated to **only one student**.
  - Allocation must be **contiguous** (no skipping books).
  - The **maximum number of pages** assigned to any student is minimized.

- The goal is to find the **minimum possible value** of the maximum pages a student can get.

Steps:
1. The minimum possible value (`start`) is the max element in the array (one book alone).
2. The maximum possible value (`end`) is the sum of all pages (one student reads all books).
3. Use Binary Search to find the minimum `mid` (maximum pages) for which allocation to `k` students is possible.
4. Check feasibility: traverse through the array and count students required if max allowed pages is `mid`.
   - If required students `<= k`, try a smaller maximum (`end = mid - 1`).
   - Else, increase allowed pages (`start = mid + 1`).

Time Complexity: O(n * log(sum - max))  
Space Complexity: O(1) – only variables used

*/

class Solution {
public:
    int findPages(vector<int> &arr, int k) {
        if (arr.size() < k)
            return -1;  // Not enough books to allocate

        int start = 0, end = 0, mid, ans;
        for (int i = 0; i < arr.size(); i++) {
            start = max(start, arr[i]); // Lower bound = max single book
            end += arr[i];              // Upper bound = sum of all pages
        }

        while (start <= end) {
            mid = start + (end - start) / 2;

            int pages = 0, cnt = 1;
            for (int i = 0; i < arr.size(); i++) {
                pages += arr[i];
                if (pages > mid) {
                    pages = arr[i]; // Assign to new student
                    cnt++;
                }
            }

            if (cnt <= k) {
                ans = mid;        // Valid answer, try smaller
                end = mid - 1;
            } else {
                start = mid + 1;  // Try larger max pages
            }
        }

        return ans;
    }
};

/*
Problem Name: Find a Peak Element

Approach: Binary Search (Optimized)

Explanation:
- A peak element is one that is not smaller than its neighbors.
- Given an array `arr`, the goal is to find **any one** peak element and return its index.
- You can assume that arr[-1] and arr[n] are negative infinity (for boundaries).
- We apply binary search:
   • If arr[mid] > arr[mid+1], move to the left half (including mid).
   • Else, move to the right half (since a peak must exist there).
- This guarantees a peak in O(log n) time.

Time Complexity: O(log n)  
Space Complexity: O(1)

*/

class Solution {
public:
    int peakElement(vector<int> &arr) {
        int start = 0, end = arr.size() - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] > arr[mid + 1]) {
                // Peak is on the left half (including mid)
                end = mid;
            } else {
                // Peak is on the right half
                start = mid + 1;
            }
        }

        return start; // start == end is the index of a peak
    }
};

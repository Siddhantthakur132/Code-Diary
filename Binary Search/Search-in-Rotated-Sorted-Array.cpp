/*
Problem Name: Find Minimum in Rotated Sorted Array

Approach: Binary Search (Optimized)

Explanation:
- The array is originally sorted in ascending order but is then rotated.
  Example: [4,5,6,7,0,1,2]
- The goal is to find the minimum element without sorting the array again.
- A simple sort-based solution takes O(n log n), but we can do it in O(log n) using binary search.

Binary Search Logic:
1. If the array is already sorted (arr[start] < arr[end]), then arr[start] is the minimum.
2. Otherwise, search in the unsorted half where the minimum exists.
3. If arr[mid] >= arr[start], it means the left part is sorted, and the minimum is in the right half.
4. Else, the minimum lies in the left half including mid.

Time Complexity: O(log n)  
Space Complexity: O(1)

*/

class Solution {
public:
    int findMin(vector<int>& arr) {
        int start = 0, end = arr.size() - 1;

        while (start < end) {
            // If the subarray is already sorted
            if (arr[start] < arr[end])
                return arr[start];

            int mid = start + (end - start) / 2;

            if (arr[mid] >= arr[start]) {
                // Left half is sorted; min must be in right half
                start = mid + 1;
            } else {
                // Min is in the left half including mid
                end = mid;
            }
        }

        return arr[start]; // or arr[end], since start == end
    }
};

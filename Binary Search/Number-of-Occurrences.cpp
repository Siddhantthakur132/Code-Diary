/*
Problem Name: Count Frequency of a Target Element in Array

Approach: Hash Map (using std::map)

Explanation:
- Given an array `arr` and an integer `target`, the task is to count how many times the target appears in the array.
- This solution uses a map (`std::map<int, int>`) to store the frequency of each element in the array.
- Once frequencies are stored, we simply return `mp[target]` if it exists, otherwise return 0.

Alternate Approach:
- A simple linear scan with a counter (commented out in the code) can also be used, which is more optimal in terms of space.

Time Complexity: O(n * log n) — due to map insertions  
Space Complexity: O(n) — storing frequencies of up to n unique elements

*/

class Solution {
public:
    int countFreq(vector<int>& arr, int target) {
        // Using map to store frequencies
        map<int, int> mp;
        for (int num : arr) {
            mp[num]++;
        }

        // Check if target is in map and return its count
        for (auto it : mp) {
            if (it.first == target) {
                return it.second;
            }
        }

        return 0; // Target not found
    }
};

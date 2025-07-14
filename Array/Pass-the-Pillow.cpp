/*
Problem Name: Pass the Pillow
LeetCode: 2582
Approach: Simulation-based Approach

Explanation:
- There are 'n' people sitting in a line, initially person 1 has the pillow.
- Every second, the pillow is passed to the next person.
- The passing continues in a back-and-forth pattern:
  e.g., 1 → 2 → 3 → ... → n → n-1 → ... → 1 → 2 → ...
- We simulate the process by incrementing a counter for each second and 
  returning the person who has the pillow at the 'time'-th second.

Time Complexity: O(time) – In the worst case, we simulate each second until we reach 'time'.
Space Complexity: O(1) – No extra space used except a few variables.

*/

class Solution {
public:
    int passThePillow(int n, int time) {
        int cnt = 0;

        while (true) {
            // Forward direction: 1 to n
            for (int i = 1; i <= n; i++) {
                if (cnt == time) {
                    return i;
                }
                cnt++;
            }
            // Backward direction: n-1 to 2
            for (int i = n - 1; i >= 2; i--) {
                if (cnt == time) {
                    return i;
                }
                cnt++;
            }
        }

        return 0; // Should never reach here
    }
};

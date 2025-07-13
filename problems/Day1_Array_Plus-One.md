---
title: Plus One – Day 1
layout: default
---

# ➕ Plus One – Day 1

## 🔍 Problem Statement
Add one to a number represented as an array of digits.

**Example:**
- Input: `[1,2,3]`
- Output: `[1,2,4]`

---

## 💡 My Approach

- Start from the last digit
- If digit is less than 9 → increment and return
- If digit is 9 → make it 0 and move left
- If all digits are 9 → insert 1 at front

---

## ⏱️ Time & Space Complexity

- **Time:** O(n)
- **Space:** O(1) (ignoring output array)

---

## 🔗 LeetCode Link  
[Plus One – LeetCode](https://leetcode.com/problems/plus-one/)

---

## 📄 Code

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i=digits.size()-1;i>=0;i--)
        {
            if(digits[i]<9)
            {
                digits[i]++;
                return digits;
            }
            else
            {
                digits[i]=0;
            }
        }
           digits.push_back(0);
           digits[0]=1;
           return digits;

    }
};

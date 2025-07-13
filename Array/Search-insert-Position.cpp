#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int start = 0, end = nums.size() - 1;
    int ans = nums.size();
    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            start = mid + 1;
        else {
            ans = mid;
            end = mid - 1;
        }
    }
    return ans;
}

int main() {
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter sorted elements: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << "Enter target value: ";
    cin >> target;

    int index = searchInsert(nums, target);
    cout << "Target should be inserted at index: " << index << endl;

    return 0;
}

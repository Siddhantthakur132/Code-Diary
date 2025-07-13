#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find intersection using two-pointer method
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    int i = 0, j = 0;
    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] == nums2[j]) {
            ans.push_back(nums1[i]);
            i++;
            j++;
        } else if (nums1[i] < nums2[j]) {
            i++;
        } else {
            j++;
        }
    }

    return ans;
}

int main() {
    int n1, n2;
    cout << "Enter number of elements in nums1: ";
    cin >> n1;

    vector<int> nums1(n1);
    cout << "Enter elements of nums1: ";
    for (int i = 0; i < n1; i++) {
        cin >> nums1[i];
    }

    cout << "Enter number of elements in nums2: ";
    cin >> n2;

    vector<int> nums2(n2);
    cout << "Enter elements of nums2: ";
    for (int i = 0; i < n2; i++) {
        cin >> nums2[i];
    }

    vector<int> result = intersect(nums1, nums2);

    cout << "Intersection: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int beautifulPairs(vector<int> A, vector<int> B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int ans = 0;
    int i = 0, j = 0;

    // Count how many values match
    while (i < A.size() && j < B.size()) {
        if (A[i] == B[j]) {
            ans++;
            i++;
            j++;
        } else if (A[i] < B[j]) {
            i++;
        } else {
            j++;
        }
    }

    // If all match, one must be broken
    if (ans == A.size()) return ans - 1;

    // Otherwise, we can improve by changing one non-matching element in B
    return ans + 1;
}

int main() {
    int n;
    cout << "Enter the size of arrays A and B: ";
    cin >> n;

    vector<int> A(n), B(n);

    cout << "Enter elements of array A: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cout << "Enter elements of array B: ";
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    int result = beautifulPairs(A, B);
    cout << "Maximum number of beautiful pairs: " << result << endl;

    return 0;
}

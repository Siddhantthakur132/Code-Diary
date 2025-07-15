#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    vector<int> arr(n), temp(n);

    // Input array elements
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Left rotate the array by 'd' positions
    // New position of each element will be (i + d) % n
    for (int i = 0; i < n; ++i) {
        temp[i] = arr[(i + d) % n];
    }

    // Output the rotated array
    for (int i = 0; i < n; ++i) {
        cout << temp[i] << " ";
    }

    return 0;
}

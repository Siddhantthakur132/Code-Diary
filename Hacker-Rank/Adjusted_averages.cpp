#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> scores(n);
    long long total = 0;

    // Input scores and compute total sum
    for (int i = 0; i < n; ++i) {
        cin >> scores[i];
        total += scores[i];
    }

    double average = (double)total / n;
    int count = 0;

    // Count how many scores are greater than the average
    for (int i = 0; i < n; ++i) {
        if (scores[i] > average)
            count++;
    }

    cout << count << endl;

    return 0;
}

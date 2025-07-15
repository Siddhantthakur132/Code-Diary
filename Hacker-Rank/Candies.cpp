#include <iostream>
#include <vector>
using namespace std;

/*
Approach:
- Give every child at least 1 candy.
- Do a left-to-right pass:
    - If current child's rating > previous, give one more candy than previous.
- Do a right-to-left pass:
    - If current child's rating > next, ensure current has more candies than next.
    - Take max(current_candy, next_candy + 1) to satisfy both directions.
- Sum all candies and return.
*/

int candies(int n, const vector<int>& ratings) {
    vector<int> candy(n, 1); // Step 1: Give all 1 candy initially

    // Step 2: Left to right
    for (int i = 1; i < n; ++i) {
        if (ratings[i] > ratings[i - 1]) {
            candy[i] = candy[i - 1] + 1;
        }
    }

    // Step 3: Right to left
    for (int i = n - 2; i >= 0; --i) {
        if (ratings[i] > ratings[i + 1]) {
            candy[i] = max(candy[i], candy[i + 1] + 1);
        }
    }

    // Step 4: Sum all candies
    int total = 0;
    for (int i = 0; i < n; ++i) {
        total += candy[i];
    }

    return total;
}

int main() {
    int n;
    cin >> n;

    vector<int> ratings(n);
    for (int i = 0; i < n; ++i) {
        cin >> ratings[i];
    }

    cout << candies(n, ratings) << endl;

    return 0;
}

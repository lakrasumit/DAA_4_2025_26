#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

long long count1 = 0, depth = 0, maxDepth = 0;

void complexRec(int n) {

    depth++; 
    count1++;
    maxDepth = max(depth, maxDepth);

    if (n <= 2) {
        depth--;
        count1++;
        return;
    }

    int p = n; 
    count1++;

    while (p > 0) {
        count1++;

        vector<int> temp(n); 
        count1++;

        for (int i = 0; i < n; i++) {
            count1++;
            temp[i] = i ^ p;
            count1++;
        }

        p >>= 1; 
        count1++;
    }

    vector<int> small(n); 
    count1++;

    for (int i = 0; i < n; i++) {
        count1++;
        small[i] = i * i; 
        count1++;
    }

    if (n % 3 == 0) {
        count1 += small.size();
        reverse(small.begin(), small.end());
    } else {
        count1 += small.size();
        reverse(small.begin(), small.end());
    }

    complexRec(n / 2);
    complexRec(n / 2);
    complexRec(n / 2);

    depth--;
}

int main() {

    int n;
    cin >> n;

    auto start = high_resolution_clock::now();

    complexRec(n);

    auto end = high_resolution_clock::now();

    cout << "No of operations: " << count1 << "\n";
    cout << "Depth: " << maxDepth << "\n";

    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " ms\n";

    return 0;
}

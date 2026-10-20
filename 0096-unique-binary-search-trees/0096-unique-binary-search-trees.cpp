class Solution {
public:
    int numTrees(int n) {
    if (n <= 1) return 1;
    int total = 0;
    for (int root = 1; root <= n; root++)
        total += numTrees(root - 1) * numTrees(n - root);
    return total;
}
};
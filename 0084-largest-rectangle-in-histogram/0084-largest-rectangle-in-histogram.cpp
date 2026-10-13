
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int st[100001];
        int top = -1;
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {
            int h;

            if (i == n)
                h = 0;
            else
                h = heights[i];

            while (top != -1 && h < heights[st[top]]) {
                int height = heights[st[top]];
                top--;

                int width;

                if (top == -1)
                    width = i;
                else
                    width = i - st[top] - 1;

                int area = height * width;

                if (area > maxArea)
                    maxArea = area;
            }

            st[++top] = i;
        }

        return maxArea;
    }
};

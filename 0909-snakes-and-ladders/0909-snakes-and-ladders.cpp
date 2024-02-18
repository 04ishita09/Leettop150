class Solution {
public:

    pair<int, int> findCoordinates(int x, int n) {
        x--;
        int row = n - 1 - x / n;
        int col = (x / n) % 2 == 0 ? x % n : n - 1 - (x % n);

        return {row, col};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        queue<int> q;
        q.push(1);
        visited[n - 1][0] = true;

        int ans = 0;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                int current = q.front();
                q.pop();

                if (current == n * n) {
                    return ans;
                }

                for (int j = 1; j <= 6 && current + j <= n * n; j++) {
                    pair<int, int> k = findCoordinates(current + j, n);

                    int nextCellValue = board[k.first][k.second] == -1 ? current + j : board[k.first][k.second];

                    if (!visited[findCoordinates(nextCellValue, n).first][findCoordinates(nextCellValue, n).second]) {
                        visited[findCoordinates(nextCellValue, n).first][findCoordinates(nextCellValue, n).second] = true;
                        q.push(nextCellValue);
                    }
                }
            }

            ans++;
        }

        return -1; // If no solution is found
    }
};
class Solution {
public:
   bool exist(vector<vector<char>>& board, string word) {
		int m = board.size();
		int n = board[0].size();
		vector<vector<bool>> visited(m, vector<bool>(n, false));

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (dfs(board, word, 0, i, j, visited)) {
					return true;
				}
			}
		}
		return false;
	}
    

    bool dfs(vector<vector<char>>& board, string word, int idx, int i, int j, vector<vector<bool>>& visited) {
		if (idx == word.length()) {
			return true;
		}
		if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] || board[i][j] != word[idx]) {
			return false;
		}
		visited[i][j] = true;
		bool res = dfs(board, word, idx + 1, i + 1, j, visited) || dfs(board, word, idx + 1, i - 1, j, visited) ||
				   dfs(board, word, idx + 1, i, j + 1, visited) || dfs(board, word, idx + 1, i, j - 1, visited);
		visited[i][j] = false;
		return res;
	}
};
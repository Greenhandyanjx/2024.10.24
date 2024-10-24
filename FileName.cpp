#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<unordered_map>
#include<numeric>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

};
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int mask = 1 << 30; // 最高位开始
        int anw = 0;
        while (mask > 0 && (m & mask) == (n & mask)) { //寻找相同前缀
            anw |= m & mask;
            mask >>= 1;
        }
        return anw;
    }
};

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int res=0;
        int n = 2;
        while (n <= right) {
            if (right-left>=n||(left%n>=right%n)) {
                n *= 2;
                continue;
            }
            res += n;
            n *= 2;
        }
        return res;
    }
};
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>res;
        if (s.length() < 11)return res;
        int l = 0, r = 10;
        unordered_map<string, int>hash;
        while (r < s.length()) {
            string temp(s.begin() + l, s.begin() + r);
            l++; r++;
            hash[temp]++;
            if (hash[temp] == 2)res.push_back(temp);
        }
        return res;
    }
};
class BSTIterator {
public:
    vector<int>vec;
    int index;
    void dfs(TreeNode* root) {
        if (root == NULL)return;
        dfs(root->left);
        vec.push_back(root->val);
        dfs(root->right);
    }
    BSTIterator(TreeNode* root) {
        dfs(root);
    }

    int next() {
        if (hasNext())return vec[index++];
        return -1;
    }

    bool hasNext() {
        return vec[index] != 0;
    }
};
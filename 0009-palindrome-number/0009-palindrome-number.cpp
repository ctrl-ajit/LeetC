class Solution {
public:
    bool isPalindrome(int x) {
         if (x < 0) return false;

        long long sum = 0;
        int original = x;

        while (x != 0) {
            int rem = x % 10;
            sum = sum * 10 + rem;
            x /= 10;
        }

        return sum == original;
        
    }
};
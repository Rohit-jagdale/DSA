class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return "";
        int start=0, maxlength = 0;

        for (int i = 0; i<s.length(); i++){
            int len1=expandAroundcenter(s, i, i);
            int len2=expandAroundcenter(s, i, i+1);

            int currentMax = max(len1, len2);
            if (currentMax>maxlength){
                maxlength = currentMax;
                start = i - (maxlength -1 )/2;
            }
        }
        return s.substr(start, maxlength);
    }
private:
    int expandAroundcenter(const string& s, int left, int right){
        while(left >= 0 && right< s.length() && s[left]==s[right]){
            left--;
            right++;
        }
        return right - left - 1;
    }
};

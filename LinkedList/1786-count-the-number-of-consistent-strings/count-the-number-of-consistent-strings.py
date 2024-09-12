class Solution(object):
    def countConsistentStrings(self, allowed, words):
        """
        :type allowed: str
        :type words: List[str]
        :rtype: int
        """
        allowed = set(allowed)
        ans = 0
        for word in words:
            flag = 1
            for c in word:
                if c not in allowed:
                    flag = 0
                    break
            if flag == 1:
                ans += 1
        return ans; 

        
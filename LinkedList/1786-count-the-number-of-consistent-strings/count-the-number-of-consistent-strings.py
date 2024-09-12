class Solution:
    def countConsistentStrings(self, allowed, words):
        allowed_characters_set = set(allowed)
        consistent_strings_count = 0
        for word in words:
            is_consistent = True  
            for character in word:
                if character not in allowed_characters_set:
                    is_consistent = False  
                    break  
            
            if is_consistent:
                consistent_strings_count += 1
        
        return consistent_strings_count

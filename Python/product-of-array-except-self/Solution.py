class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """

        output = []
        zeros = 0
        product = 1
        for num in nums:
            if num == 0:
                zeros+=1
            else:
                product *= num
        
        if zeros > 1:
            output = [0 for _ in nums]
        elif zeros == 1:
            output = [product if num==0 else 0 for num in nums]
        else:
            output = [product/num for num in nums]
        
        return output

        
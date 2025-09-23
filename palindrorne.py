def is_palindrome(num):
    # Negative numbers are not palindromes
    if num < 0:
        return False
    
    # Compare number with its reverse
    return str(num) == str(num)[::-1]


# Example usage
n = int(input("Enter a number: "))
if is_palindrome(n):
    print(n, "is a palindrome number.")
else:
    print(n, "is not a palindrome number.")

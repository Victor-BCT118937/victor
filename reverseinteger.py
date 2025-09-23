def reverse_integer(n):
    # Handle negative numbers
    sign = -1 if n < 0 else 1
    n *= sign

    # Reverse the integer
    reversed_num = int(str(n)[::-1])

    return sign * reversed_num


# Example usage
num = int(input("Enter an integer: "))
print("Reversed integer:", reverse_integer(num))

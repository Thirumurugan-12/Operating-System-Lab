echo "Enter the first number:"
read num1
echo "Enter the second number:"
read num2

# Check which number is greater
if [ "$num1" -gt "$num2" ]; then
    echo "The greatest number is: $num1"
elif [ "$num2" -gt "$num1" ]; then
    echo "The greatest number is: $num2"
else
    echo "Both numbers are equal."
fi

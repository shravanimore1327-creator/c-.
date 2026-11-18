
#!/bin/bash

# Accept number of elements
echo "Enter how many numbers (1 to 25):"
read n

if [ "$n" -lt 1 ] || [ "$n" -gt 25 ]; then
    echo "Invalid input!"
    exit 1
fi

# Read numbers using redirection
> numbers.txt

echo "Enter $n numbers:"
for ((i=1; i<=n; i++))
do
    read num
    echo "$i $num" >> numbers.txt
done

# Create separate files
> even.txt
> odd.txt
> prime.txt

# Check even, odd and prime numbers
while read i num
do
    if [ $((num % 2)) -eq 0 ]; then
        echo "$i $num" >> even.txt
    else
        echo "$i $num" >> odd.txt
    fi

    if [ "$num" -ge 2 ]; then
        flag=1

        for ((j=2; j*j<=num; j++))
        do
            if [ $((num % j)) -eq 0 ]; then
                flag=0
                break
            fi
        done

        if [ "$flag" -eq 1 ]; then
            echo "$i $num" >> prime.txt
        fi
    fi
done < numbers.txt

# Create sorted files for join
sort -k1,1n numbers.txt > sorted1.txt
sort -k1,1n even.txt > sorted2.txt
sort -k1,1n odd.txt > sorted3.txt
sort -k1,1n prime.txt > sorted4.txt

# Use join command
join -1 1 -2 1 sorted1.txt sorted2.txt > even_result.txt
join -1 1 -2 1 sorted1.txt sorted3.txt > odd_result.txt
join -1 1 -2 1 sorted1.txt sorted4.txt > prime_result.txt

# Display first 5 even numbers
echo "First 5 even numbers:"
awk 'NR<=5 {print $3}' even_result.txt

# Display first 5 odd numbers
echo "First 5 odd numbers:"
awk 'NR<=5 {print $3}' odd_result.txt

# Display first 5 prime numbers
echo "First 5 prime numbers:"
awk 'NR<=5 {print $3}' prime_result.txt


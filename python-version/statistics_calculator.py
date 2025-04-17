
"""
Program: Statistics Calculator (Python Version)
This program asks the user to enter a list of integers and then calculates
the Mean, Median, and Mode using an Object-Oriented Programming (OOP) approach.
"""

from collections import Counter

class StatisticsCalculator:
    """
    This class encapsulates all functionality for calculating
    mean, median, and mode from a list of integers.
    """

    def __init__(self, numbers):
        """
        Constructor to initialize the list of integers.
        :param numbers: List of integers.
        """
        self.numbers = numbers

    def calculate_mean(self):
        """
        Calculates the mean (average) of the list of integers.
        """
        total = sum(self.numbers)
        count = len(self.numbers)
        mean = total / count
        return mean

    def calculate_median(self):
        """
        Calculates the median (middle value) of the list.
        """
        sorted_numbers = sorted(self.numbers)
        n = len(sorted_numbers)

        if n % 2 == 1:
            median = sorted_numbers[n // 2]
        else:
            mid1 = sorted_numbers[n // 2 - 1]
            mid2 = sorted_numbers[n // 2]
            median = (mid1 + mid2) / 2

        return median

    def calculate_mode(self):
        """
        Calculates the mode (most frequent value(s)) in the list.
        """
        counts = Counter(self.numbers)
        max_freq = max(counts.values())
        mode = [num for num, freq in counts.items() if freq == max_freq]
        return mode


def get_user_input():
    """
    Prompts the user to enter integers separated by space,
    and returns them as a list of integers.
    """
    while True:
        try:
            raw_input = input("Enter integers separated by space: ")
            numbers = list(map(int, raw_input.strip().split()))
            if len(numbers) == 0:
                print("Please enter at least one number.")
                continue
            return numbers
        except ValueError:
            print("Invalid input. Please enter only integers.")


# Main logic
if __name__ == "__main__":
    # Ask user for input
    user_numbers = get_user_input()

    # Create calculator instance
    calc = StatisticsCalculator(user_numbers)

    # Print results
    print("\nInput Numbers:", user_numbers)
    print("Mean:", calc.calculate_mean())
    print("Median:", calc.calculate_median())
    print("Mode:", calc.calculate_mode())

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class BigInteger {
private:
    std::vector<int> digits; // Store digits in reverse order
    bool isNegative;

    void trim() {
        while (digits.size() > 1 && digits.back() == 0)
            digits.pop_back();
        if (digits.size() == 1 && digits[0] == 0)
            isNegative = false;
    }

public:
    BigInteger() : isNegative(false) {}
    
    BigInteger(const std::string &num) {
        isNegative = (num[0] == '-');
        for (int i = num.size() - 1; i >= (isNegative ? 1 : 0); --i)
            digits.push_back(num[i] - '0');
        trim();
    }

    friend std::ostream& operator<<(std::ostream &os, const BigInteger &num) {
        if (num.isNegative) os << "-";
        for (int i = num.digits.size() - 1; i >= 0; --i)
            os << num.digits[i];
        return os;
    }

    friend std::istream& operator>>(std::istream &is, BigInteger &num) {
        std::string input;
        is >> input;
        num = BigInteger(input);
        return is;
    }

    BigInteger operator+(const BigInteger &other) const {
        if (isNegative == other.isNegative) {
            BigInteger result;
            result.isNegative = isNegative;
            int carry = 0, sum;
            size_t maxSize = std::max(digits.size(), other.digits.size());
            
            for (size_t i = 0; i < maxSize || carry; ++i) {
                sum = carry;
                if (i < digits.size()) sum += digits[i];
                if (i < other.digits.size()) sum += other.digits[i];
                result.digits.push_back(sum % 10);
                carry = sum / 10;
            }
            return result;
        }
        return *this - (-other);
    }

    BigInteger operator-() const {
        BigInteger result = *this;
        if (!result.isZero())
            result.isNegative = !isNegative;
        return result;
    }

    BigInteger operator-(const BigInteger &other) const {
        if (isNegative != other.isNegative) return *this + (-other);
        if (*this == other) return BigInteger("0");
        
        bool resultNegative = (*this < other);
        const BigInteger &larger = resultNegative ? other : *this;
        const BigInteger &smaller = resultNegative ? *this : other;

        BigInteger result;
        result.isNegative = resultNegative;
        int borrow = 0;
        
        for (size_t i = 0; i < larger.digits.size(); ++i) {
            int diff = larger.digits[i] - borrow - (i < smaller.digits.size() ? smaller.digits[i] : 0);
            borrow = (diff < 0);
            result.digits.push_back((diff + 10) % 10);
        }
        result.trim();
        return result;
    }

    bool isZero() const {
        return digits.size() == 1 && digits[0] == 0;
    }

    bool operator==(const BigInteger &other) const {
        return isNegative == other.isNegative && digits == other.digits;
    }

    bool operator!=(const BigInteger &other) const {
        return !(*this == other);
    }

    bool operator<(const BigInteger &other) const {
        if (isNegative != other.isNegative) return isNegative;
        if (digits.size() != other.digits.size())
            return (digits.size() < other.digits.size()) ^ isNegative;
        for (int i = digits.size() - 1; i >= 0; --i)
            if (digits[i] != other.digits[i])
                return (digits[i] < other.digits[i]) ^ isNegative;
        return false;
    }

    bool operator>(const BigInteger &other) const {
        return other < *this;
    }

    bool operator<=(const BigInteger &other) const {
        return !(*this > other);
    }

    bool operator>=(const BigInteger &other) const {
        return !(*this < other);
    }
};

int main() {
    BigInteger num1, num2;
    std::cout << "Enter two large numbers: ";
    std::cin >> num1 >> num2;
    
    std::cout << "Sum: " << num1 + num2 << "\n";
    std::cout << "Difference: " << num1 - num2 << "\n";
    std::cout << "Comparison: " << (num1 > num2 ? "num1 > num2" : "num1 <= num2") << "\n";
    return 0;
}
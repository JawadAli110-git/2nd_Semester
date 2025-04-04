#include <iostream>
#include <vector>
#include <algorithm>

class Polynomial;

class PolynomialUtils {
public:
    static int evaluate(const Polynomial &p, int x);
    static Polynomial derivative(const Polynomial &p);
};

class Polynomial {
private:
    std::vector<int> coefficients;

    void trim() {
        while (!coefficients.empty() && coefficients.back() == 0)
            coefficients.pop_back();
    }

public:
    Polynomial() {}
    Polynomial(const std::vector<int>& coeffs) : coefficients(coeffs) { trim(); }

    Polynomial operator+(const Polynomial& other) const {
        size_t maxSize = std::max(coefficients.size(), other.coefficients.size());
        std::vector<int> result(maxSize, 0);
        
        for (size_t i = 0; i < coefficients.size(); ++i)
            result[i] += coefficients[i];
        for (size_t i = 0; i < other.coefficients.size(); ++i)
            result[i] += other.coefficients[i];
        
        return Polynomial(result);
    }

    Polynomial operator-(const Polynomial& other) const {
        size_t maxSize = std::max(coefficients.size(), other.coefficients.size());
        std::vector<int> result(maxSize, 0);
        
        for (size_t i = 0; i < coefficients.size(); ++i)
            result[i] += coefficients[i];
        for (size_t i = 0; i < other.coefficients.size(); ++i)
            result[i] -= other.coefficients[i];
        
        return Polynomial(result);
    }

    Polynomial operator*(const Polynomial& other) const {
        std::vector<int> result(coefficients.size() + other.coefficients.size() - 1, 0);
        
        for (size_t i = 0; i < coefficients.size(); ++i) {
            for (size_t j = 0; j < other.coefficients.size(); ++j) {
                result[i + j] += coefficients[i] * other.coefficients[j];
            }
        }
        
        return Polynomial(result);
    }

    friend std::ostream& operator<<(std::ostream& os, const Polynomial& p) {
        if (p.coefficients.empty()) {
            os << "0";
            return os;
        }
        
        bool first = true;
        for (int i = p.coefficients.size() - 1; i >= 0; --i) {
            if (p.coefficients[i] != 0) {
                if (!first) os << (p.coefficients[i] > 0 ? " + " : " - ");
                else if (p.coefficients[i] < 0) os << "-";
                
                if (std::abs(p.coefficients[i]) != 1 || i == 0) os << std::abs(p.coefficients[i]);
                if (i > 0) os << "x";
                if (i > 1) os << "^" << i;
                
                first = false;
            }
        }
        return os;
    }
    
    friend class PolynomialUtils;
};

int PolynomialUtils::evaluate(const Polynomial &p, int x) {
    int result = 0, power = 1;
    for (int coeff : p.coefficients) {
        result += coeff * power;
        power *= x;
    }
    return result;
}

Polynomial PolynomialUtils::derivative(const Polynomial &p) {
    if (p.coefficients.size() <= 1) return Polynomial({0});
    
    std::vector<int> deriv(p.coefficients.size() - 1);
    for (size_t i = 1; i < p.coefficients.size(); ++i) {
        deriv[i - 1] = p.coefficients[i] * static_cast<int>(i);
    }
    
    return Polynomial(deriv);
}

int main() {
    Polynomial p1({1, -3, 2}); // 2x^2 - 3x + 1
    Polynomial p2({0, 1, 4}); // 4x^2 + x
    
    std::cout << "P1: " << p1 << "\n";
    std::cout << "P2: " << p2 << "\n";
    std::cout << "P1 + P2: " << p1 + p2 << "\n";
    std::cout << "P1 - P2: " << p1 - p2 << "\n";
    std::cout << "P1 * P2: " << p1 * p2 << "\n";
    
    std::cout << "Evaluation of P1 at x = 2: " << PolynomialUtils::evaluate(p1, 2) << "\n";
    std::cout << "Derivative of P1: " << PolynomialUtils::derivative(p1) << "\n";
    
    return 0;
}
#include <iostream>
#include <string>

class Overcoat {
private:
    std::string type;
    double price;

public:
    Overcoat() : type(""), price(0.0) {}

    Overcoat(const std::string& t, double p) : type(t), price(p) {}

    Overcoat& operator=(const Overcoat& other) {
        if (this == &other) return *this;
        type = other.type;
        price = other.price;
        return *this;
    }

    bool operator==(const Overcoat& other) const {
        return type == other.type;
    }

    bool operator>(const Overcoat& other) const {
        if (type == other.type) {
            return price > other.price;
        }
        return false;
    }

    void print() const {
        std::cout << "Тип одягу: " << type << ", Ціна: " << price << "\n";
    }
};

class Flat {
private:
    double area;
    double price;

public:
    Flat() : area(0.0), price(0.0) {}

    Flat(double a, double p) : area(a), price(p) {}

    Flat& operator=(const Flat& other) {
        if (this == &other) return *this;
        area = other.area;
        price = other.price;
        return *this;
    }

    bool operator==(const Flat& other) const {
        return area == other.area;
    }

    bool operator>(const Flat& other) const {
        return price > other.price;
    }

    void print() const {
        std::cout << "Площа: " << area << " кв.м, Ціна: " << price << "\n";
    }
};

int main() {
    system("chcp 1251>null");
    std::cout << "=== Тестування класу Overcoat ===\n";
    Overcoat coat1("Palto", 3500.0);
    Overcoat coat2("Palto", 4200.0);
    Overcoat coat3("Kurtka", 2500.0);

    coat1.print();
    coat2.print();
    coat3.print();

    if (coat1 == coat2) {
        std::cout << "coat1 та coat2 мають однаковий тип.\n";
    }
    else {
        std::cout << "coat1 та coat2 мають різний тип.\n";
    }

    if (coat2 > coat1) {
        std::cout << "coat2 дорожче за coat1.\n";
    }

    Overcoat coat4;
    coat4 = coat1;
    std::cout << "Після присвоєння (coat4 = coat1):\n";
    coat4.print();

    std::cout << "\n=== Тестування класу Flat ===\n";
    Flat flat1(65.5, 75000.0);
    Flat flat2(65.5, 82000.0);
    Flat flat3(45.0, 50000.0);

    flat1.print();
    flat2.print();
    flat3.print();

    if (flat1 == flat2) {
        std::cout << "flat1 та flat2 мають однакову площу.\n";
    }
    else {
        std::cout << "flat1 та flat2 мають різну площу.\n";
    }

    if (flat2 > flat3) {
        std::cout << "flat2 дорожче за flat3.\n";
    }

    Flat flat4;
    flat4 = flat3;
    std::cout << "Після присвоєння (flat4 = flat3):\n";
    flat4.print();

    return 0;
}

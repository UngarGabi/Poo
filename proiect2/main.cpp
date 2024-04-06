#include <iostream>
#include <cstring>
#include <vector>
//Exchange care schimba banii cu care ai venit in alta moneda.
class Currency {
private:
    std::string nume;
    double cursvalutar;

public:
    Currency(std::string nume, double cursvalutar) {
        this->nume = nume;
        this->cursvalutar = cursvalutar;
    }

    double cumpara(double lei) {
        return lei / cursvalutar;
    }

    double vinde(double bani) {
        return bani * cursvalutar;
    }

    std::string getnume() {
        return nume;
    }
};

class Client {
private:
    std::string nume;
    double suma;
    Currency currency;

public:
    Client(std::string nume, double suma, Currency& currency) : nume(nume), suma(suma), currency(currency) {}

    double tranzactie(Currency& moneda) {
        return moneda.cumpara(suma);
    }

    double tranzactieInvers(Currency& moneda) {
        return moneda.vinde(suma);
    }

    double getbani() {
        return suma;
    }

    std::string getmoneda() {
        return currency.getnume();
    }

    std::string getclient() {
        return nume;
    }
};

class ListaClienti {
private:
    std::vector<std::string> numec;
public:
    void adauga(const std::string& nume) {
        numec.push_back(nume);
    }

    void afiseaza() {
        std::cout << "Lista clienti:" << '\n';
        for (const auto& nume : numec) {
            std::cout << nume << '\n';
        }
    }
};

int main() {
    ListaClienti lista;
    Currency euro("EUR", 4.97);
    Currency usd("USD", 4.5);
    int ok=1;
    double suma;
    std::string nume;
    char moneda[4],t[4];
    while(ok==1) {
        std::cout << "Nume client:";
        std::cin >> nume;
        std::cout << "Nr bani pe care vrei sa-i schimbi:";
        std::cin >> suma;
        std::cout << "Moneda(RON/EUR/USD):";
        std::cin >> moneda;
        Client client(nume, suma, usd);

        lista.adauga(client.getclient());
        if (strcmp("RON", moneda) == 0) {
            std::cout << "In ce moneda schimbati?" << '\n';
            std::cin >> t;
            if (strcmp("EUR", t) == 0) {
                double euro1 = client.tranzactie(euro);
                std::cout << suma << " RON = " << euro1 << " " << euro.getnume() << '\n';
            }
            else
            if (strcmp("USD", t) == 0) {
                double usd1 = client.tranzactie(usd);
                std::cout << suma << " RON = " << usd1 << " " << usd.getnume() << '\n';
            }
            else
                std::cout << "Moneda introdusa nu este buna"<< '\n';
        }
        else
        if (strcmp("EUR", moneda) == 0) {
            double lei1 = client.tranzactieInvers(euro);
            std::cout << suma << " " << "EUR = " << lei1 << " " << "LEI" << '\n';
        }
        else
        if (strcmp("USD", moneda) == 0) {
            double lei1 = client.tranzactieInvers(usd);
            std::cout << suma << " " << "USD = " << lei1 << " " << "LEI" << '\n';
        }
        else
            std::cout << "Moneda introdusa nu este buna" << '\n';

        std::cout << "Mai sunt clienti?(Da/Nu)" << '\n';
        std::cin >> t;
        if(strcmp(t,"Da")!=0)
            ok=0;

    }
    lista.afiseaza();
    return 0;
}

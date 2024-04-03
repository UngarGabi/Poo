#include <iostream>
#include <cstring>
#include <vector>
//Scrie nr de bani pe care vrei sa l schimbi si va parea in functie de moneda introdusa LEI/EURO/USD transformarea ei in alta moneda
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
        std::cout << "Lista clienti:\n";
        for (const auto& nume : numec) {
            std::cout << nume << "\n";
        }
    }
};

int main() {
    ListaClienti lista;
    Currency euro("EUR", 4.97);
    Currency usd("USD", 4.5);
    double lei;
    char moneda[10];
    std::cout << "Nr bani pe care vrei sa-i schimbi:";
    std::cin >> lei;
    std::cout << "Moneda:";
    std::cin >> moneda;
    Client client("ANA", lei, euro);
    Client client1("MARA",lei,usd);
    lista.adauga(client.getclient());
    lista.adauga(client1.getclient());

    if (strcmp("RON", moneda) == 0) {
        double euro1 = client.tranzactie(euro);
        std::cout << lei << " RON = " << euro1 << " " << euro.getnume() << '\n';
        double usd1 = client.tranzactie(usd);
        std::cout << lei << " RON = " << usd1 << " " << usd.getnume() << '\n';
    }
    else {
        double lei1 = client.tranzactieInvers(euro);
        std::cout << lei1 << " " << "RON" << '\n';
        double lei2 = client.tranzactie(usd);
        std::cout << lei << " " << "RON" << '\n';
    }

    lista.afiseaza();
    return 0;
}